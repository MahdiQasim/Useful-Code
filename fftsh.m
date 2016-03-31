function m=fftsh(img)
[m n]=size(img);
img=double(img);
for i=1:m
    for j=1:n
        img(i,j)=((-1)^(i+j))*img(i,j);
    end
end
m=img;