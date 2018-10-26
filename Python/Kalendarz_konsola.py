import calendar
from getch import *

def rok():
	print("Podaj rok: ")
	rok = int(raw_input())
	print(calendar.TextCalendar(calendar.MONDAY).formatyear(rok, 2, 1, 1, 3))

def miesiac_func():
	print("Podaj rok: ")
	rok = int(raw_input())
	print("Podaj miesiac: ")
	miesiac = int(raw_input())

	print(calendar.month(rok, miesiac))



while(1):
	print("1. Wyswietl caly rok")
	print("2. Wyswietl wybrany miesiac")
	print("3. Koniec")
	wybor = int(raw_input())

	if wybor == 1:
		rok()

	elif wybor == 2:
		miesiac_func()

	elif wybor == 3:
		klawisz()
		break
	else:
		print("Zle dane!")

#kalendarz_miesiac = calendar.month(rok, miesiac)
#miesiac_label = Label(root, text=kalendarz_miesiac, font=('courier', 10, 'bold'), justify = LEFT,)

#kalendarz_rok = calendar.TextCalendar(calendar.MONDAY).formatyear(rok, 2, 1, 1, 3)
#rok_label = Label(root, text=kalendarz_rok, font=('courier', 10, 'bold'), justify = LEFT,)
