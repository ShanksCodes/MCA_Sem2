import pyperclip
import keyboard

clipboard_queue = []

def copy_to_clipboard():
    data = pyperclip.paste()
    clipboard_queue.append(data)

def paste_from_clipboard(index):
    if index >= 1 and index <= len(clipboard_queue):
        pyperclip.copy(clipboard_queue[index-1])

def handle_hotkey(index):
    def wrapper():
        paste_from_clipboard(index)
    return wrapper

def main():
    for i in range(1, 10):  # Customize the range as per your preference
        keyboard.add_hotkey(f"shift+{i}", handle_hotkey(i))
    
    keyboard.add_hotkey('ctrl+c', copy_to_clipboard)

    keyboard.wait()

if __name__ == '__main__':
    main()
