import xml.etree.ElementTree as ET
import os,sys
import shutil

# 读取XML文件
tree = ET.parse('MDK-ARM/TESTAI4.uvprojx_bk')
root = tree.getroot()
# print(ET.tostring(root, encoding='utf-8').decode())

# 遍历Targets标签下的每一个Target标签
for target in root.findall('./Targets/Target/Groups/Group'):
    group_name = target.find('GroupName').text
    print("Group Name:", group_name)


directory_path = './lvgl'
# 获取目录下的所有文件名
def list_files(directory_path):
    file_path = []
    file_names = []
    for root, directories, files in os.walk(directory_path):
        for file_name in files:
            file_path.append(os.path.join(root, file_name).replace('./', '../').replace('\\','/'))
            file_names.append(file_name)
    return file_names,file_path

# 调用递归函数列出文件
file_names,file_paths = list_files(directory_path)
# print(file_names,file_paths)

# for file_name, file_path in zip(file_names, file_paths):
#     if file_name.endswith('.h'):
#         source_path = file_path.replace('../','./')
#         destination_path = os.path.join('./lvgl/inc', file_name)
#         shutil.copy2(source_path, destination_path)

for target in root.findall('./Targets/Target/Groups/Group'):
    if target.find('GroupName').text == 'GUI':
        target.append(ET.Element('Files'))
        files = target.find('Files')
        # print("Group Name:", target.find('GroupName').text)
        for file_name, file_path in zip(file_names, file_paths):
            if file_name.endswith('.c'):
                file_element = ET.Element('File')
                fileName_element = ET.SubElement(file_element, 'FileName')
                fileName_element.text = file_name
                fileType_element = ET.SubElement(file_element, 'FileType')
                fileType_element.text = '1'
                filePath_element = ET.SubElement(file_element, 'FilePath')
                filePath_element.text = file_path
                files.append(file_element)

# 创建一个新的ElementTree对象，并将XML声明添加到根元素中
new_tree = ET.ElementTree(root)
new_tree.write('MDK-ARM/TESTAI4.uvprojx', encoding='utf-8', xml_declaration=True)