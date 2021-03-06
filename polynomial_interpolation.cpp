// attribution arjan_bal github
/*
  Given n points (x[i], y[i]), computes an n-1-degree polynomial p that
  passes through them: p(x) = a[0]*x^0 + ... + a[n-1]*x^{n-1}.
  Time: O(n^2)
  To work modulo a prime, replace the divisions with modinverse
 */
typedef vector<double> vd;
vd interpolate(vd x, vd y) {
	int n=x.size();
	vd res(n,0), temp(n,0);
	for(int k=0;k<n;k++) 
		for(int i=k+1;i<n;i++)
			y[i] = (y[i] - y[k]) / (x[i] - x[k]);
	double last = 0; temp[0] = 1;
	for(int k=0;k<n;k++) 
		for(int i=0;i<n;i++) {
			res[i] += y[k] * temp[i];
			swap(last, temp[i]);
			temp[i] -= last * x[k];
		}
	return res;
}

vll interpolate(vll x, vll y, int mod) {
	int n=x.size();
	vll res(n,0), temp(n,0);
	for(int k=0;k<n;k++) 
		for(int i=k+1;i<n;i++)
			y[i] = (y[i] - y[k] + mod) * inv(x[i] - x[k] + mod, mod) % mod;
	ll last = 0; temp[0] = 1;
	for(int k=0;k<n;k++) 
		for(int i=0;i<n;i++) {
			res[i] = (res[i] + y[k] * temp[i])%mod;
			swap(last, temp[i]);
			temp[i] = (temp[i] - last * x[k] % mod + mod)%mod;
		}
	return res;
}