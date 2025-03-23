from PIL import Image, ImageDraw, ImageFont

a4_width = 2480
a4_height = 3508
lines_in_page = 6
page_layout = [4, 5, 5, 5, 5, 5]

lines = [Image.open("%d.png"%name) for name in range(29)]
cropped_lines = [line.crop((5,0,2880-5,707)) for line in lines]
img_ratio = cropped_lines[0].height / cropped_lines[0].width
new_width = a4_width - 100
new_height = int(new_width * img_ratio)
resized_lines = [line.resize((new_width, new_height), Image.ANTIALIAS) for line in cropped_lines]

pages = []
start_of_lines = 0
for n_of_lines in page_layout:
    A4_Canvas = Image.new("RGB", (a4_width, a4_height), "white")
    total_space = a4_height - sum(line.height for line in resized_lines[start_of_lines:start_of_lines+n_of_lines])
    spacing = total_space // 6
    y_offset = 0
    
    if n_of_lines - 5 < 0:
        draw = ImageDraw.Draw(A4_Canvas)
        title_font = ImageFont.truetype("~/Library/Fonts/BMJUA_ttf.ttf", 200)
        title_text = "Title"
        text_width, text_height = draw.textsize(title_text, font=title_font)
        draw.text(((a4_width - text_width) // 2, 150), title_text, fill="black", font=title_font)
        y_offset += int(spacing*1.75)
        
    for line in resized_lines[start_of_lines:start_of_lines+n_of_lines]:
        y_offset += spacing
        A4_Canvas.paste(line, (50, y_offset))
        y_offset += line.height
        
    start_of_lines += n_of_lines
    pages.append(A4_Canvas)
    #A4_Canvas.show()

pages[0].save(
    "Title.pdf",
    save_all=True,
    append_images=pages[1:]
)
