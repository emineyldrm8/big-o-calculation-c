# big-o-calculation-c
big o calculation c
# ÖZET
Bilgisayar bilimleri ve benzeri bilimlerde istenilen soruya kars¸ılık her zaman istenilen cevaplar en hızlı veya en kesin sonucu   verecek   Algoritma   ve   yo¨ntemler   olmayabilir.   Bu durumun  nedeni  yazılan  yo¨ntem  ve  algoritmanın  verimlilig˘i ile ilgilidir. Algoritma ne kadar verimli c¸alıs¸ır ve istenilene ne kadar yakın olursa kodun performansı o kadar iyi olmaktadır. Bu  durumlar  altında  kullandıg˘ımız  algoritmaların  bize  olan zaman ve hafıza maliyetlerini hesaplamak, bunlar hakkında bilgi sahibi olmak c¸ok o¨nemlidir. Bu iki terim aslında beraber algoritmanın verimlilig˘ini belirtmektedir. ˙Iyi bir algoritmadan az yer kaplaması ve az zaman harcaması beklenir.

Problemi    c¸o¨zmek    ic¸in    algoritmanın    harcadıg˘ı    zamanın analizi   zaman   karmas¸ıklıg˘ını,   gerekli   belleg˘in   analizi   ise yer(space)   karmas¸ıklıg˘ının   hesabını   gerektirir.   Hesaplanan karmas¸ıklıkları  analiz  etmek  ve  bunları  temsil  etmek  ic¸in, Asimptotik Notasyon kullanılmaktadır.

# GİRİŞ
Bu projenin amacı kullanici tarafından verilen kodun, Big O
notasyonu hesabından yararlanarak algoritma karmas¸ıklıgını ˘
hesaplamaktır.Bizlerden istenen dosyadan okunan kodun tam
karmas¸ıklıgının hesaplanmasıdır.Proje kapsamındaki isterler ˘
as¸agıda sıralanmaktadır. ˘
1.Dosya ic¸erisinden kodun okunması ve Dosyanın ic¸eriginin ˘
kontrol edilmesi
2.Dosyadan okunan kodun Big O notasyonuna gore Zaman ¨
karmas¸ıklıgının hesaplanması ˘
3.Dosyadan okunan kodun Big O notasyonuna gore yer ¨
(Hafıza) karmas¸ıklıgının hesaplanması ˘
4.Dosyadan okunan kodun c¸alıs¸tırıldıgında gec¸en s ˘ urenin ¨
hesaplanması

As¸ag˘ıda  Big  O  notasyonunun  hesaplanmasına  dair  o¨rnek kodlar yer almaktadır.

void printAllNumbersThenAllPairSums(int arr[], int size) for (int i = 0; i ¡ size; i++)
printf(”%d”, arr[i]);
}for (int i = 0; i ¡ size; i++)
{for (int j = 0; j ¡ size; j++)
{printf(”}
}
}
Zaman karmas¸ıklıg˘ı: O(n+n2) = O(n2)

# YÖNTEM
˙lk olarak bu projeye bas¸lamadan o¨nce uzun bir su¨re konu taraması ve kaynak aras¸tırması yaptık.Big o notasyonunun hem   zaman   hem   hafıza   karmas¸ıklıg˘ı   ile   alakalı   bilgiler edindik.Edindig˘imiz   bilgiler   sonucunda   kendimize   bir   yol haritası c¸izdik ve algoritmamızı olus¸turduk.
˙Is¸e ilk isteri yapmakla bas¸ladık.Dosyadan okunan metnin bir kod   olup   olmadıg˘ını   anlayabilmek   ic¸in   o¨g˘retmenlerimiz tarafından     verilen     o¨rneklerden     yola     c¸ıkarak     dosya ic¸erisinde  ”main”  kelimesini  aras¸tırmanın  mantıklı  olacag˘ını du¨s¸u¨ndu¨k.Bo¨ylece  dosyayı  satır  satır  okuyup  her  satırında ”main” kelimesinin kontrolu¨nu¨  yaptık.Eg˘er ic¸erisinde ”main” kelimesi  gec¸iyorsa  dosyanın  ic¸erig˘i  bir  koddur  yoksa  dosya ic¸erig˘i kod deg˘ildir.
Daha sonra ikinci isteri yapmaya gec¸tik.C¸ alıs¸malarımıza gore kodumuz for,while ve do-while d ¨ ong ¨ uleri ic¸in ¨
zaman karmas¸ıklıgını hesaplamaktadır.Bunu da s¸u yolla ˘
gerc¸ekles¸tirdik: ˙Ilk bas¸ta kodu satır satır okuduk.For
dong ¨ us¨ u ic¸in kod ic¸inde ”for” kontrol ¨ u yaptık.For d ¨ ong ¨ us¨ u¨
kontrollerinde ise susl ¨ u parantezlerden yararlandık.S ¨ usl ¨ u¨
parantezlerin sayısına ve varlıklarına gore is¸lemlerimizi ¨
gerc¸ekles¸tirdikKontrol sonucunda ”for” bulunuyorsa ic¸ic¸e
for dong ¨ us¨ u kontrol ¨ u yapmaya gec¸iyoruz.B ¨ oylece for ¨
dong ¨ us¨ un¨ un varlı ¨ gını kod ic¸erisinde aramıs¸ oluyoruz.Di ˘ ger ˘
dong ¨ u c¸es¸itleri ic¸inde aynı algoritmayı farklı hesaplarla ¨
gerc¸ekles¸tiriyoruz.Yapılan dong ¨ u kontrolleri sonucunda kodda ¨
dong ¨ u bulunmazsa geriye de ¨ gis¸ken kontrol ˘ u sonucu zaman ¨
karmas¸ıklıgı hesaplanıyor. ˘
Uc¸ ¨ unc ¨ u istere gelince burada ise ikinci isterde kullandı ¨ gımız ˘
yontemi kullanmanın daha iyi olaca ¨ gını d ˘ us¸¨ und ¨ uk.B ¨ oylece ¨
but¨ un dosyayı yine satır satır okuyup her satır ic¸erisinde ¨
yazdıgımız fonksiyonlardan yararlanarak ”int,float,double” ˘
gibi degis¸ken tipi kontrol ˘ u yaparak bunları bellekte ¨
kapladıkları alan degerleriyle c¸arpıp yer karmas¸ıklı ˘ gını ˘
hesapladık.Return komutu ic¸in ise yine aynı s¸ekilde kod
ic¸erisindeki tekrar sayisini hesaplayarak bellek boyutunu
c¸arptık.Aynı s¸ekilde kodun dizi ic¸erip ic¸ermedigine ˘
eger ic¸eriyorsa kac¸ adet tekrarlandı ˘ gına bakıyoruz.Bu ˘
ister ic¸in eksikligimiz ise kod ic¸erisindeki dizinin t ˘ ur¨ un¨ u¨
bulamamızdan ve dizinin bellek boyutunu hesaplayamamızdan
kaynaklanıyor.Bu da yer karmas¸ıklıgı hesabının eksik ˘
yapılmasına sebep olmaktadır.

<br></br>
![image](https://user-images.githubusercontent.com/73225797/221414665-4063b2c3-13d1-44b5-8e31-473e955eb8d8.png)
<br></br>
![image](https://user-images.githubusercontent.com/73225797/221414682-bdbcc25a-68dc-4ed0-bd7c-0796d4b04279.png)
<br></br>
Do¨rdu¨ncu¨  isteri ise forumda sorulan bir soruya verilen cevabı baz   alarak   yaptık.Verilen   cevapta   kodun   c¸alıs¸tırılmasında gec¸en  su¨renin  hesaplanması  isterinin  hem  t(n)’li  bir  ifade s¸eklinde hem de saniye cinsinden hesaplanmasının kabul edileceg˘i  so¨ylenmektedir.T(n)’li  zaman  hesabının  internette kaynak  sayısı  c¸ok  azdı  bu  nedenle  biz  de  kodumuzu  basit do¨ngu¨ler ic¸in c¸alıs¸abilecek s¸ekilde hazırladık.C¸ alıs¸malarımıza go¨re   kodumuz   for,do-while   ve   while   do¨ngu¨lerinin   T(n) hesabını  basit  du¨zeyde  gerc¸ekles¸tirebiliyor.Saniye  cinsinden zaman hesabına gelirsek kodun c¸alıs¸tırılmasında gec¸en su¨renin saniye cinsinden hesaplanmasını clock() fonksiyonundan yararlanarak gerc¸ekles¸tirdik.
<br></br>
![image](https://user-images.githubusercontent.com/73225797/221414713-b3a6b9cc-f1b7-4d37-9de7-5d27ff4659e9.png)
<br></br>

# KULLANILAN ÖNEMLİ FONKSİYONLAR
int artiskontrolu(char dizi[], FILE *fptr) : Koddaki islemlerin artis seklini kontrol eden ve buna gore belirlenen sayaclara degisim miktarini yansitan fonksiyon.

int kontrol(char dizi[], FILE*fptr) : For dongusu icin kontrol yapan fonksiyondur.

int tngenelhesap(char dizi[],FILE* fptr) : T(n) hesaplamasını yapan fonksiyon.

int   icicebigoicinkarar(char   dizi[],   FILE*fptr)   :   ic¸ic¸e   for do¨ngu¨su¨  ic¸in big o hesaplamasını yapan fonksiyon.

int whileicinbigo(char dizi[],FILE* fptr) : while do¨ngu¨su¨  ic¸in big o hesaplamasını yapan fonksiyon.
<br></br>
![image](https://user-images.githubusercontent.com/73225797/221414805-6ef0cd38-fa80-4f04-a2dc-9ced3989e446.png)

