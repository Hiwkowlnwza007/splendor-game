import pandas as pd

# 1. โหลดข้อมูลจากไฟล์ Excel (สมมติว่าไฟล์ชื่อ splendor_data.xlsx และอยู่หน้า Sheet ชื่อ Development)
df = pd.read_excel('data_of_card.xlsx', sheet_name='dev_card')

# 2. แปลงร่างเป็น CSV (ตั้งชื่อว่า dev_cards.csv)
# index=False คือบอกว่าไม่เอาตัวเลขรันบรรทัดด้านหน้าสุด
df.to_csv('dev_cards.csv', index=False) 

print("✅ แปลงไฟล์ไพ่พัฒนาเสร็จเรียบร้อย! พร้อมให้ C++ ใช้งาน")

df = pd.read_excel('data_of_card.xlsx', sheet_name='nob_card')

# 2. แปลงร่างเป็น CSV (ตั้งชื่อว่า dev_cards.csv)
# index=False คือบอกว่าไม่เอาตัวเลขรันบรรทัดด้านหน้าสุด
df.to_csv('nob_cards.csv', index=False) 

print("✅ แปลงไฟล์ไพ่ขุนนางเสร็จเรียบร้อย! พร้อมให้ C++ ใช้งาน")
