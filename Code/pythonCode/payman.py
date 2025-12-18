import json
import os
from datetime import datetime

DATA_FILE = "bills.json"


# ========================
# 文件操作
# ========================
def load_bills():
    if not os.path.exists(DATA_FILE):
        return []
    try:
        with open(DATA_FILE, "r", encoding="utf-8") as f:
            return json.load(f)
    except json.JSONDecodeError:
        print("⚠ 数据文件损坏，已重置")
        return []


def save_bills(bills):
    with open(DATA_FILE, "w", encoding="utf-8") as f:
        json.dump(bills, f, ensure_ascii=False, indent=2)


# ========================
# 输入工具
# ========================
def input_date(prompt, allow_empty=False):
    while True:
        s = input(prompt).strip()
        if allow_empty and s == "":
            return datetime.today().strftime("%Y-%m-%d")
        try:
            datetime.strptime(s, "%Y-%m-%d")
            return s
        except ValueError:
            print("❌ 日期格式应为 YYYY-MM-DD")


def input_float(prompt):
    while True:
        try:
            value = float(input(prompt))
            if value < 0:
                raise ValueError
            return value
        except ValueError:
            print("❌ 请输入合法的非负数字")


def pause():
    input("\n按回车继续...")


# ========================
# 业务功能
# ========================
def add_bill(bills):
    print("\n=== 添加账单 ===")
    date = input_date("日期 (YYYY-MM-DD，回车默认今天)：", allow_empty=True)

    bill_type = input("类型 (income / expense)：").strip().lower()
    if bill_type not in ("income", "expense"):
        print("❌ 类型只能是 income 或 expense")
        return

    amount = input_float("金额：")
    note = input("备注：").strip()

    bills.append({"date": date, "type": bill_type, "amount": amount, "note": note})

    save_bills(bills)
    print("✅ 添加成功")


def show_bills(bills):
    print("\n=== 所有账单 ===")
    if not bills:
        print("暂无账单")
        return

    for i, b in enumerate(bills, 1):
        print(
            f"{i:>2}. {b['date']} | {b['type']:7} | "
            f"{b['amount']:8.2f} | {b['note']}"
        )


def query_by_date(bills):
    print("\n=== 按日期查询 ===")
    start = input_date("开始日期：")
    end = input_date("结束日期：")

    result = [b for b in bills if start <= b["date"] <= end]

    if not result:
        print("未找到记录")
        return

    for b in result:
        print(f"{b['date']} | {b['type']:7} | {b['amount']:8.2f} | {b['note']}")


def statistics_all(bills):
    income = sum(b["amount"] for b in bills if b["type"] == "income")
    expense = sum(b["amount"] for b in bills if b["type"] == "expense")

    print("\n=== 总体统计 ===")
    print(f"总收入：{income:.2f}")
    print(f"总支出：{expense:.2f}")
    print(f"结余：  {income - expense:.2f}")


def statistics_by_month(bills):
    print("\n=== 按月份统计 ===")
    month = input("请输入月份 (YYYY-MM)：").strip()

    income = 0
    expense = 0

    for b in bills:
        if b["date"].startswith(month):
            if b["type"] == "income":
                income += b["amount"]
            else:
                expense += b["amount"]

    print(f"{month} 收入：{income:.2f}")
    print(f"{month} 支出：{expense:.2f}")
    print(f"{month} 结余：{income - expense:.2f}")


# ========================
# 菜单
# ========================
def show_menu():
    print("\n==============================")
    print("   个人账单管理系统")
    print("==============================")
    print("1. 添加账单")
    print("2. 查看所有账单")
    print("3. 按日期查询")
    print("4. 总体统计")
    print("5. 按月份统计")
    print("0. 退出")
    print("==============================")


def main():
    bills = load_bills()

    while True:
        show_menu()
        choice = input("请选择：").strip()

        if choice == "1":
            add_bill(bills)
            pause()
        elif choice == "2":
            show_bills(bills)
            pause()
        elif choice == "3":
            query_by_date(bills)
            pause()
        elif choice == "4":
            statistics_all(bills)
            pause()
        elif choice == "5":
            statistics_by_month(bills)
            pause()
        elif choice == "0":
            print("👋 再见")
            break
        else:
            print("❌ 无效选择")


if __name__ == "__main__":
    main()
