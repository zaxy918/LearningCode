# userinput=input()
# if len(userinput)==18:
#     if userinput[0:17].isdigit() and userinput[17].capitalize() == "X" or userinput[17].isdigit():  
#         year=2025-int(userinput[6:10])
#         month=int(userinput[10:12])
#         day=int(userinput[12:14])
#         if year >=0 and month >0 and month <=12 and day >0 and day<=31:
#             if int(userinput[16])%2==0:
#                 print(f"{year}  女")
#             else:
#                 print(f"{year}  男")
#         else:
#             print("粗o")

from datetime import datetime

def check_id(idstr: str) -> dict:
    res = {
        "valid": False,
        "age": None,
        "gender": None,
        "msg": ""
    }
    if len(idstr) != 18:
        res['msg'] = "Length error"
        return res
    if not idstr[:17].isdigit() or not (idstr[17].isdigit() or idstr[17].capitalize() == "X"):
        res["msg"] = "Invalid id"
        return res
    try:
        birthstr = idstr[6:14]
        birthdate = datetime.strptime(birthstr, "%Y%d%m")
        if birthdate > datetime.now():
            res["msg"] = "Invalid birth"
            return res
    except ValueError:
        res["msg"] = "Invalid date"
        return res
    today = datetime.now()
    age = today.year - birthdate.year
    if (today.month, today.day) < (birthdate.month, birthdate.day):
        age -= 1
    gender_code = int(idstr[16])
    gender = "M" if gender_code % 2 == 1 else "F"
    res["age"] = age
    res["gender"] = gender
    res["msg"] = "Valid"
    res["valid"] = True
    return res
# time_ = date(2006,9,18)
# print(time_.strftime("%Y\%m\%d"))
# timestr = "yy20200908"
# timem = datetime.strptime(timestr,"yy%Y%d%m")
# print(timem)

# print(timem - timedelta(days=1))

# print(time_.day)

# d=input()
# m=int(input())
# datem=datetime.strptime(d,"%Y-%m-%d")
# out=date(datem.year, m + 1, 1)
# print(out - timedelta(days=1))

# try:
#     datetime(2020,-1,0)
# except ValueError:
#     print("Wrong")
    