# 🔗 Pipex

Pipex, shell'deki pipe (`|`) operatörünün davranışını simüle eden bir C programıdır. İki komutu birbirine bağlayarak ilk komutun çıktısını ikinci komutun girdisi olarak kullanır.

## 📋 İçindekiler

- [Proje Hakkında](#proje-hakkında)
- [Özellikler](#özellikler)
- [Kurulum](#kurulum)
- [Kullanım](#kullanım)
- [Proje Yapısı](#proje-yapısı)
- [Teknik Detaylar](#teknik-detaylar)
- [Örnek Kullanımlar](#örnek-kullanımlar)

## 🎯 Proje Hakkında

Pipex, 42 Okulu müfredatının bir parçasıdır ve Unix sistem programlama kavramlarını öğretmeyi amaçlar. Program, shell'de şu komutun yaptığını yapar:

```bash
< file1 cmd1 | cmd2 > file2
```

Bu komut, `file1` dosyasını okur, `cmd1` komutuna girdi olarak verir, `cmd1`'in çıktısını `cmd2`'ye pipe eder ve son olarak sonucu `file2`'ye yazar.

## ✨ Özellikler

- **Pipe İşlemleri**: İki süreci pipe ile birbirine bağlar
- **Fork Mekanizması**: Her komut için ayrı child process oluşturur
- **Dosya İşlemleri**: Girdi ve çıktı dosyalarını yönetir
- **Hata Yönetimi**: Kapsamlı hata kontrolü ve mesajları
- **Bellek Yönetimi**: Memory leak'siz güvenli bellek kullanımı
- **PATH Çözümleme**: Komutları sistem PATH'inden otomatik bulur

## 🚀 Kurulum

### Gereksinimler

- GCC veya Clang derleyici
- Make
- Unix/Linux işletim sistemi

### Derleme

```bash
# Projeyi klonlayın
git clone [repo-url]
cd pipex

# Derleyin
make

# Temizlik (object dosyaları)
make clean

# Tam temizlik (executable dahil)
make fclean

# Yeniden derleme
make re
```

## 💻 Kullanım

### Temel Sözdizimi

```bash
./pipex file1 cmd1 cmd2 file2
```

### Parametreler

- `file1`: Girdi dosyası
- `cmd1`: İlk komut ve argümanları
- `cmd2`: İkinci komut ve argümanları
- `file2`: Çıktı dosyası

### Shell Eşdeğeri

```bash
./pipex infile "ls -l" "wc -l" outfile
```

Bu komut aşağıdaki shell komutuna eşdeğerdir:

```bash
< infile ls -l | wc -l > outfile
```

## 📁 Proje Yapısı

```
pipex/
├── Makefile              # Derleme dosyası
├── README.md             # Dokümantasyon
├── pipex.h               # Header dosyası
├── pipex.c               # Ana program
├── transactions/         # İşlem fonksiyonları
│   ├── close_multi.c     # Çoklu fd kapatma
│   ├── create_pipe.c     # Pipe oluşturma
│   ├── execute_cmd.c     # Komut çalıştırma
│   ├── find_cmd_path.c   # Komut yolu bulma
│   ├── first_process.c   # İlk child process
│   ├── second_process.c  # İkinci child process
│   ├── get_cmd_path.c    # PATH çözümleme
│   ├── open_input_file.c # Girdi dosyası açma
│   ├── open_output_file.c# Çıktı dosyası açma
│   └── split_cmd.c       # Komut ayrıştırma
└── utils/                # Yardımcı fonksiyonlar
    ├── ft_split.c        # String ayırma
    ├── ft_strdup.c       # String kopyalama
    ├── ft_strjoin.c      # String birleştirme
    ├── ft_strlen.c       # String uzunluğu
    ├── ft_strncmp.c      # String karşılaştırma
    └── ft_substr.c       # Substring alma
```

## 🔧 Teknik Detaylar

### Kullanılan Sistem Çağrıları

- `fork()`: Yeni process oluşturma
- `pipe()`: Pipe oluşturma
- `dup2()`: File descriptor yönlendirme
- `execve()`: Komut çalıştırma
- `waitpid()`: Child process'leri bekleme
- `open()`, `close()`: Dosya işlemleri
- `access()`: Dosya erişim kontrolü

### Çalışma Mantığı

1. **Dosya Açma**: Girdi ve çıktı dosyaları açılır
2. **Pipe Oluşturma**: İki process arası iletişim için pipe oluşturulur
3. **First Process**: 
   - Fork ile child process oluşturulur
   - STDIN, girdi dosyasına yönlendirilir
   - STDOUT, pipe'ın yazma ucuna yönlendirilir
   - İlk komut çalıştırılır
4. **Second Process**:
   - Fork ile ikinci child process oluşturulur
   - STDIN, pipe'ın okuma ucuna yönlendirilir
   - STDOUT, çıktı dosyasına yönlendirilir
   - İkinci komut çalıştırılır
5. **Bekleme**: Parent process, her iki child'ın tamamlanmasını bekler

### Bellek Yönetimi

- Dinamik ayrılan tüm bellek uygun şekilde serbest bırakılır
- Split işlemlerinde hata durumunda kısmi bellek temizliği yapılır
- File descriptor'lar kullanım sonrası kapatılır

## 📝 Örnek Kullanımlar

### Örnek 1: Satır Sayma

```bash
# Input dosyasındaki satırları listele ve say
./pipex input.txt "cat" "wc -l" output.txt

# Shell eşdeğeri:
< input.txt cat | wc -l > output.txt
```

### Örnek 2: Grep ve Sort

```bash
# "error" içeren satırları bul ve sırala
./pipex log.txt "grep error" "sort" errors.txt

# Shell eşdeğeri:
< log.txt grep error | sort > errors.txt
```

### Örnek 3: Liste İşlemleri

```bash
# Dizin listesini al ve belirli kalıpla filtrele
./pipex infile "ls -l" "grep .c" output.txt

# Shell eşdeğeri:
< infile ls -l | grep .c > output.txt
```

### Örnek 4: Komut Zincirleme

```bash
# Kelime sayma ve filtreleme
./pipex data.txt "cat" "wc -w" wordcount.txt

# Shell eşdeğeri:
< data.txt cat | wc -w > wordcount.txt
```

## ⚠️ Hata Durumları

Program aşağıdaki durumlarda hata mesajı verir:

- Yanlış argüman sayısı
- Girdi dosyası bulunamadı veya okunamadı
- Çıktı dosyası oluşturulamadı
- Komut bulunamadı (PATH'de yok)
- Pipe oluşturma hatası
- Fork hatası
- Execve hatası

## 🎓 Öğrenilen Kavramlar

- Process yönetimi (fork, execve, wait)
- Inter-process communication (IPC) - Pipes
- File descriptor manipülasyonu
- UNIX sistem çağrıları
- Bellek yönetimi ve pointer kullanımı
- Hata yönetimi ve debugging

## 📄 Lisans

Bu proje 42 Okulu müfredatının bir parçasıdır.

---

⭐ Faydalı bulduysanız yıldız vermeyi unutmayın!
