#!/bin/bash

# 1. المرحلة الأولى: إنشاء الملف وإضافة 50 التزام (Commit)
touch index.html

for i in {1..200}
do
    # إضافة تعديل بسيط داخل الملف لتسجيل التغيير
    echo "Test Repo Syestem $i" >> index.html
    
    git add .
    git commit -m "Test Repo System $i"
    git push origin main
    
    echo "Done commit $i - waiting 5 seconds..."
    
    # الانتظار لمدة 10 ثوانٍ قبل التكرار التالي
    sleep 7
done

# 2. المرحلة الثانية: حذف الملف وإرسال التعديل النهائي
rm index.html

git add .
git commit -m "Delete Tests Repo System"
git push origin main

echo "Done successfully!"