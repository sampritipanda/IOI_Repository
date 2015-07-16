// Very Fast Multiplication

#include <iostream>
#include <algorithm>
#include <complex>
#include <valarray>

using namespace std;

const double PI = 3.141592653589793238460;

typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;

// Cooley–Tukey FFT (in-place)
void fft(CArray& x)
{
  const size_t N = x.size();
  if (N <= 1) return;

  // divide
  CArray even = x[std::slice(0, N/2, 2)];
  CArray  odd = x[std::slice(1, N/2, 2)];

  // conquer
  fft(even);
  fft(odd);

  // combine
  for (size_t k = 0; k < N/2; ++k)
  {
    Complex t = std::polar(1.0, -2 * PI * k / N) * odd[k];
    x[k    ] = even[k] + t;
    x[k+N/2] = even[k] - t;
  }
}

// inverse fft (in-place)
void ifft(CArray& x)
{
  // conjugate the complex numbers
  x = x.apply(std::conj);

  // forward fft
  fft( x );

  // conjugate the complex numbers again
  x = x.apply(std::conj);

  // scale the numbers
  x /= x.size();
}

int main()
{
  int N; cin >> N;

  while(N--) {
    string num1, num2; cin >> num1 >> num2;
    int N1 = num1.length(), N2 = num2.length();
    int padded_size = 2 * (1 << int(ceil(log2(max(N1, N2)))));
    vector<Complex> num1_vec(padded_size - N1, 0.0), num2_vec(padded_size - N2, 0.0);

    for(int i = 0; i < N1; i++) num1_vec.push_back(double(num1[i] - '0'));
    for(int i = 0; i < N2; i++) num2_vec.push_back(double(num2[i] - '0'));

    CArray data1(padded_size);
    for(int i = 0; i < padded_size; i++) data1[i] = num1_vec[i];
    CArray data2(padded_size);
    for(int i = 0; i < padded_size; i++) data2[i] = num2_vec[i];

    fft(data1);
    fft(data2);

    CArray data3(padded_size);
    data3 = data1 * data2;

    ifft(data3);

    vector<long long> ans;
    for (int i = 0; i < padded_size; i++) {
      ans.push_back((long long)(round(data3[i].real())));
    }

    for(int i = padded_size - 1; i >= 0; i--) cout << ans[i] << " ";
    cout << endl;
  }
}
