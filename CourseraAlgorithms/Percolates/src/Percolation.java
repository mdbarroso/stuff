public class Percolation {
	
	private WeightedQuickUnionUF _ufAlg;
	private int _arraySize;
	private boolean[] _states;
	
	public Percolation(int N)
	{
		_ufAlg = new WeightedQuickUnionUF(N*N + 2);	// virtual top + virtual bottom
		_states = new boolean[N*N + 2];				// virtual top + virtual bottom
		_arraySize = N;
		
		for (int i = 1; i <= _arraySize; i++)
		{
			_ufAlg.union(0, i);					// connect top line to virtual top
			_ufAlg.union(N*N + 1, getId(i, N));	// connect bottom line to virtual bottom
		}
	}
	
	private int getId(int i, int j)
	{
		return i + (j - 1) * _arraySize;
	}
	
	private int[] getNearOpenNodes(int i, int j)
	{
		int size = 4; 	// at most, you have 4 neighbors
		int[][] help = new int[4][2];	// container for the x-y coordinates of the 4 hypothetical 
		
		// initialize helper array
		for (int iter = 0; iter < 4; iter++) {help[iter][0] = -1; help[iter][0] = -1;}
		
		if (1 >= i) --size;
		else {help[0][0] = i - 1;help[0][1] = j;}
		
		if (_arraySize <= j) --size;
		else {help[1][0] = i;help[1][1] = j + 1;}
		
		if (_arraySize <= i) --size;
		else {help[2][0] = i + 1;help[2][1] = j;}
		
		if (1 >= j) --size;
		else {help[3][0] = i;help[3][1] = j - 1;}
		
		int[] neighbors = new int[size];

		
int skippedNeighbor = 0;
		for (int iter = 0; iter < 4; iter++)
			if (help[iter][0] != -1)
			{	
				int neighborId = getId(help[iter][0], help[iter][1]);
				if (_states[neighborId])	// open state
				{
					neighbors[iter - skippedNeighbor] = neighborId;
				}
			}
			else ++skippedNeighbor;

		return neighbors;
	}
	
	public void open (int i, int j) throws IndexOutOfBoundsException
	{	
		if ( i < 1 || i > _arraySize || j < 1 || j > _arraySize)	throw new IndexOutOfBoundsException("i: " + i + "; j: " + j + "; They must be greater or equal to 1, and less or equal to " + _arraySize);
		int currentId = getId(i,j);
		int[] neighbors = getNearOpenNodes(i, j);
		_states[currentId] = true;
		
		for (int neighborId : neighbors)
			if (neighborId != 0) _ufAlg.union(neighborId, currentId);
	}
	
	public boolean isOpen(int i, int j)
	{
		if ( i < 1 || i > _arraySize || j < 1 || j > _arraySize)	throw new IndexOutOfBoundsException("i: " + i + "; j: " + j + "; They must be greater or equal to 1, and less or equal to " + _arraySize);
		return (_states[getId(i,j)]) ;
	}
	
	public boolean isFull(int i, int j)
	{
		if ( i < 1 || i > _arraySize || j < 1 || j > _arraySize)	throw new IndexOutOfBoundsException("i: " + i + "; j: " + j + "; They must be greater or equal to 1, and less or equal to " + _arraySize);
		return _ufAlg.connected(getId(i,j), 0);
	}
	
	public boolean percolates()
	{
		if (_arraySize == 1) return true;
		return _ufAlg.connected(0, _arraySize*_arraySize + 1);
	}
	
	public static void main(String[] args)
	{
		int N = 20;	// default value
		String validPattern = "[0-9]+";
		for (String arg : args)
			if (arg.matches(validPattern))
				N = Integer.parseInt(arg);
			
		Percolation perObject = new Percolation(N);
		int openedSites = 0;
		while (!perObject.percolates())
		{
			int i = StdRandom.uniform(N) + 1, j = StdRandom.uniform(N) + 1;
			
			if (!perObject.isOpen(i,j))
			{
				perObject.open(i, j);
				openedSites++;
			}
		}		
		double percolationThreshold = ((double) openedSites) / (perObject._arraySize * perObject._arraySize);
		StdOut.println("Opened [" + openedSites + "] sites");
		StdOut.println("Total site size: " + perObject._arraySize * perObject._arraySize);
		StdOut.println("Percolation threshold: " + percolationThreshold);
	}
}