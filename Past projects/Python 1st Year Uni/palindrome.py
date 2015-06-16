def wordPalindrome(word):
    word = word.lower()
    word = ''.join(e for e in word if e.isalnum())

    if word[0:len(word)]==word[::-1]:
        return True
    else:
        return False

x = wordPalindrome("Go hang a salami – I’m a lasagna hog")
print x
