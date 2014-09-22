
public class PercolationStats {

	private double[] _percolationResults;
	
	public PercolationStats(int N, int T)
	{
		_percolationResults = new double[T];
		for (int i = 0; i < T; i++) _percolationResults[i] = 0;
	}
	
	public double mean()
	{
		return StdStats.mean(_percolationResults);
	}
	
	public double stddev()
	{
		return StdStats.stddev(_percolationResults);
	}
	
	public double confidenceLo()
	{
		return mean() - 1.96 * stddev()/Math.sqrt(_percolationResults.length);
	}
	
	public double confidenceHi()
	{
		return mean() + 1.96 * stddev()/Math.sqrt(_percolationResults.length);
	}

	public static void main(String[] args) {
		if (args.length != 2) throw new IllegalArgumentException("PercolationStats receives 2 command line arguments: N - number of items - & T - number of times to run the percolation tests");
		int N = Integer.valueOf(args[0]), T = Integer.valueOf(args[1]);
		if (N <= 0 || T <= 0) throw new IllegalArgumentException("N & T must be positive integers: >= 0");
		
		PercolationStats percStats = new PercolationStats(N,T);
		
		for (int i = 0; i < T; i++)
		{
			Percolation perObject = new Percolation(N);
			int openedSites = 0;
			while (!perObject.percolates())
			{
				int x = StdRandom.uniform(N) + 1, y = StdRandom.uniform(N) + 1;
				
				if (!perObject.isOpen(x,y))
				{
					perObject.open(x, y);
					openedSites++;
				}
			}		
			percStats._percolationResults[i] = ((double) openedSites) / (N * N);
//			StdOut.println("Opened [" + openedSites + "] sites");
//			StdOut.println("Total site size: " + N * N);
//			StdOut.println("Percolation threshold: " + percStats._percolationResults[i]);
		}
		StdOut.println("mean			= " + percStats.mean());
		StdOut.println("stddev			= " + percStats.stddev());
		StdOut.println("95% confidence interval = " + percStats.confidenceLo() + ", " + percStats.confidenceHi());
	}
}
