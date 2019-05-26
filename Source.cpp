#include "Header.h"

IPoly::IPoly() {
	p.clear();
	n = 0;
}
IPoly::IPoly(vector <ui> poly) {
	p = poly;
	n = p.size();
	for (ui i = 0; i < n; i++)
		p[i] %= MODULE;
}
ui IPoly::value(ui x) {
	ui res = 0, buf = 1;
	for (int i = 0; i < n; i++) {
		res += (p[i] * buf) % MODULE;
		buf *= x;
		buf %= MODULE;
	}
	return res;
}
IPoly IPoly::operator= (IPoly b) {
	p = b.p;
	n = b.n;
	return *this;
}
IPoly operator+ (IPoly a, IPoly b) {
	vector <ui> r(max(a.n, b.n), 0);
	for (ui i = 0; i < min(a.n, b.n); i++) {
		r[i] = (a.p[i] + b.p[i]) % MODULE;
	}
	for (ui i = min(a.n, b.n); i < max(a.n, b.n); i++) {
		if (a.n < b.n)
			r[i] = b.p[i];
		else
			r[i] = a.p[i];
	}
	IPoly res(r);
	return res;
}
IPoly operator- (IPoly a, IPoly b) {
	vector <ui> r(max(a.n, b.n), 0);
	for (int i = 0; i < b.n; i++)
		b.p[i] = (MODULE - b.p[i]) % MODULE;
	for (ui i = 0; i < min(a.n, b.n); i++) {
		r[i] = (a.p[i] + b.p[i]) % MODULE;
	}
	for (ui i = min(a.n, b.n); i < max(a.n, b.n); i++) {
		if (a.n < b.n)
			r[i] = b.p[i];
		else
			r[i] = a.p[i];
	}
	int i = r.size() - 1;
	while (i >= 1 && !r[i])	{
		r.pop_back();
		i--;
	}
	IPoly res(r);
	return res;
}
IPoly operator* (IPoly a, IPoly b) {
	vector <ui> r(a.n + b.n - 1, 0);
	for (ui i = 0; i < a.n; i++)
		for (ui j = 0; j < b.n; j++)	{
			r[i + j] += (a.p[i] * b.p[j]) % MODULE;
			r[i + j] %= MODULE;
		}
	IPoly res(r);
	return res;
}
IPoly operator/ (IPoly a, IPoly b) {
	IPoly res;
	if (b.n > a.n)
		return res;
	vector <ui> r(a.n - b.n + 1, 0);
	for (int i = r.size() - 1; i >= 0; i--) {
		r[i] = a.p[i + b.n - 1] / b.p[b.n - 1];
		r[i] %= MODULE;
		for (int j = b.n - 1; j >= 0; j--) {
			a.p[i + j] -= (b.p[j] * r[i]) % MODULE;
			a.p[i + j] %= MODULE;
		}
	}
	res = IPoly(r);
	return res;
}
IPoly operator% (IPoly a, IPoly b) {
	if (b.n > a.n)
		return a;
	vector <ui> r(a.n - b.n + 1, 0);
	for (int i = r.size() - 1; i >= 0; i--) {
		r[i] = a.p[i + b.n - 1] / b.p[b.n - 1];
		r[i] %= MODULE;
		for (int j = b.n - 1; j >= 0; j--) {
			a.p[i + j] -= (b.p[j] * r[i]) % MODULE;
			a.p[i + j] %= MODULE;
		}
		a.n--;
	}
	int i = a.n - 1;
	while (i >= 1 && !a.p[i]) {
		a.p.pop_back();
		a.n--;
		i--;
	}
	return a;
}

IPoly IPoly::derivate() {
	vector <ui> buf(n - 1, 0);
	for (int i = 1; i < n; i++)
		buf[i - 1] = (i * p[i]) % MODULE;
	return IPoly(buf);

}

IPoly IPoly::integrate() {
	vector <ui> buf(n + 1, 0);
	for (int i = 1; i <= n; i++)
		buf[i] = (p[i - 1] / i) % MODULE;
	int i = n - 1;
	while (i >= 1 && !buf[i]) {
		buf.pop_back();
		i--;
	}
	return IPoly(buf);
}
ui IPoly::integrate(ui a, ui b) {
	vector <ui> buf(n + 1, 0);
	for (int i = 1; i <= n; i++)
		buf[i] = (p[i - 1] / i) % MODULE;
	int i = n;
	while (i >= 1 && !buf[i]) {
		buf.pop_back();
		i--;
	}
	IPoly res(buf);
	return (res.value(b) - res.value(a)) % MODULE;
}

void IPoly::print(ostream & out) {
	out << p[0];
	if (n > 1)
		out << " + " << p[1] << "x";
	for (int i = 2; i < n; i++) {
		out << " + " << p[i] << "x^" << i;
	}
}