package mynative;

//Napisz program z wykorzystaniem JNI.
//Niech w klasie bÄdÄ trzy metody natywne sĹuĹźÄce do obliczania iloczynu skalarnego dwĂłch wektorĂłw.
//Schemat implementacji tej klasy powinien byÄ jak pokazano poniĹźej.

public class MyNative {
	
static {
	System.loadLibrary("MyNative");
}

private Double[] a;
private Double[] b;
private Double c;

public Double[] getA(){
	return a;
}
public Double[] getB(){
return b;
}
public double getC(){
	return c;
}

public void setA(Double[] a){
	this.a = a;
}
public void setB(Double[] b){
	this.b = b;
}
public void setC(double c){
	this.c = c;
}

public native Double multi01(Double[] a, Double[] b);
//zakładamy, że po stronie kodu natywnego wyliczony zostanie iloczyn skalarny dwóch wektorów
public native Double multi02(Double[] a); 
//zakładamy, że drugi atrybut będzie pobrany z obiektu przekazanego do metody natywnej 
public native void multi03();
//zakładamy, że po stronie natywnej utworzone zostanie okienko na atrybuty,
//a po ich wczytaniu i przepisaniu do a,b obliczony zostanie wynik. 
//Wynik powinna wyliczać metoda Javy multi04 
//(korzystając z parametrów a,b i wpisująca wynik do c).

private void multi04(){ // mnoży a i b, wynik wpisuje do c
	Double result = 0.0;
	for (int i = 0; i < a.length; i ++) {
		result += a[i] * b[i];
	}
	c = result;
}

}

