import vigenerecipher
import string
import re
def gcd(a,b):
    if a<b:
        a,b=b,a
    if a%b==0:
        return b
    else:
        return gcd(b,a%b)

def findstr(Ctext,str_):
    interval_list=[]
    loc=0
    array_locs=[]
    while loc<len(Ctext):
        loc=Ctext.find(str_,loc)
        
        if loc==-1:
            break
        array_locs.append(loc)
        loc=loc+1
    index=0
    while index+1<len(array_locs):
        interval=array_locs[index+1]-array_locs[index]
        print("�����",interval)
        interval_list.append(interval)
        index=index+1
    interval_len=gcd(interval_list[0],interval_list[1])
    print("���ظ�ֵΪ",str_,"ʱ������֮���������������",interval_len,"\n")
    return interval_len
    
def find_repeat(Ciphertext,repeat_list):
    while len(Ciphertext)>200:
        Ciphertext=list(Ciphertext)
        Ciphertext.pop(1)
        Ciphertext=''.join(Ciphertext)
        list1=re.findall(r'.{3}',Ciphertext)
    
        list2=[0]*len(list1)
        
        for i in range(len(list1)):
            for j in range(len(list1)):
                if(list1[i]==list1[j]):
                    list2[i]=list2[i]+1
                    
        max_len=max(list2)
        a=list2.index(max(list2))

        if list1[a] not in repeat_list:
            if max_len==3:
                repeat_list.append(list1[a])
                print("�ظ�����������",max_len)
                print("�ظ�ֵ��",list1[a])
                print("\n")

def check_len(Ciphertext,interval_len):
    ListCiphertext=list(Ciphertext)
    Keylength=1

    while Keylength<interval_len+1:
        #ָ����ʼ��Ϊ��
        CoincidenceIndex = 0

        #ʹ����Ƭ����
        for i in range(Keylength):
            Numerator = 0
            PresentCipherList = ListCiphertext[i::Keylength]

            #ʹ�ü���ȥ�أ�����ÿһ���������غ�ָ��
            for Letter in set(PresentCipherList):
                Numerator += PresentCipherList.count(Letter) * (PresentCipherList.count(Letter)-1)
            CoincidenceIndex += Numerator/(len(PresentCipherList) * (len(PresentCipherList)-1))

        #���������������غ�ָ����ƽ��ֵ
        Average=CoincidenceIndex / Keylength
        Keylength += 1

        #��ֵ��0.6�����˳�ѭ��
        if Average > 0.06:
            break

    Keylength -= 1
    print("���غ�ָ����֤����Կ���������Ϊ:",Keylength,"\n")
    return Keylength
def keyword(Ciphertext,keylength):
    ListCiphertext = list(Ciphertext)
    #��׼������Դ�ڿα�
    Standard = {'A':0.082,'B':0.015,'C':0.028,'D':0.043,'E':0.127,'F':0.022,'G':0.020,'H':0.061,'I':0.070,'J':0.002,'K':0.008,'L':0.040,'M':0.024,'N':0.067,'O':0.075,'P':0.019,'Q':0.001,'R':0.060,'S':0.063,'T':0.091,'U':0.028,'V':0.010,'W':0.023,'X':0.001,'Y':0.020,'Z':0.001}

    while True:
        KeyResult = []

        for i in range(keylength):
            # ʹ����Ƭ����
            PresentCipherList = ListCiphertext[i::keylength]

            #��ʼ���غ�ָ�����ֵΪ���������ƶ�λ����Ӧ�ַ��ԣ�����
            QuCoincidenceMax = 0
            KeyLetter = "*"

            #�����ƶ���λ��
            #m����Կ��Ӧ��Ӣ����ĸ
            for m in range(26):
                #��ʼ����ǰ�ƶ�λ�����غϻ�ָ��Ϊ��
                QuCoincidencePresent = 0

                #���������غ�ָ���������ַ���Ƶ�ʣ���ӦӢ���ַ����ֵı�׼Ƶ�ʣ������ĺ�
                for Letter in set(PresentCipherList):
                    #fi/n
                    LetterFrequency = PresentCipherList.count(Letter) / len(PresentCipherList)

                    # ��׼Ƶ��
                    #ord(Letter) - 65�ǽ�letter��Ӧ����ĸ��Ϊ26�ڵ���ֵ��Ȼ����m���㣬�õ���k�Ƕ�Ӧ��������ĸ
                    k = chr( ( ord(Letter) - 65 - m ) % 26 + 65 )
                    StandardFrequency = Standard[k]

                    #�����غϻ�ָ�����ۼӱ���26��Ӣ����ĸ
                    QuCoincidencePresent = QuCoincidencePresent + LetterFrequency * StandardFrequency

                #��������������غ�ָ�������ֵ��ͬʱ�����ӦӦ�Ե�λ��������Ӧkey���ַ�
                if QuCoincidencePresent > QuCoincidenceMax:
                    QuCoincidenceMax = QuCoincidencePresent
                    #m��26��Ӣ�Ķ�Ӧ��λ�ã���0��ʼ��+65����ΪA��ascii����65
                    KeyLetter = chr( m +65 )
            print("��",i+1,"����Կ��ĸΪ:",KeyLetter,"��Ӧ���غϻ�ָ��Ϊ:",QuCoincidenceMax)
            #���浱ǰλ��key��ֵ���˳�ѭ����������һ���������ƶ�λ���ĳ���
            KeyResult.append( KeyLetter )
        #�б�תΪ�ַ���
        Key = "".join(KeyResult)
        break
    return Key

if __name__ == '__main__':

    Ciphertext = input("�������ģ�").upper()
    repeat_list=[]
    find_repeat(Ciphertext,repeat_list)
    print("kasisiki���Է�:\n�ظ��б�",repeat_list)
    for m in repeat_list:
        interval_len=findstr(Ciphertext,m)
    
    key_len=check_len(Ciphertext,interval_len)

    KeyResult = keyword(Ciphertext,key_len)

    print("��Կ�����Ϊ��" , KeyResult,"\n")

    #��֪��Կ����python�Դ�ά�����ǽ���
    ClearText = vigenerecipher.decode( Ciphertext,KeyResult )
    print("���ܽ��Ϊ��" , ClearText)


