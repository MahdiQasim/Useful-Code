% Adaptive median filter, the function receive two argument.
% An input image and the maximum size of the median filter.
% The intial size of the filter is 3X3.

function g=adpmedf(img,smax)
pad=floor(smax/2);
img=padarray(img,[pad pad],'replicate');
[m n]=size(img);
for i=pad+1:m-pad
    for j=pad+1:n-pad
        windowsize=3;
        f=1;
        zxy=img(i,j);
        while (f)
            mask=img(i-floor(windowsize/2):i+floor(windowsize/2),j-floor(windowsize/2):j+floor(windowsize/2));
            mask=reshape(mask,1,windowsize*windowsize);
            mask=sort(mask);
            mini=min(mask);
            maxi=max(mask);
            med=mask(ceil(length(mask)/2));
            
            if(med>mini && med<maxi)
                if(zxy>mini && zxy<maxi)
                    img(i-pad,j-pad)=zxy;
                else
                    img(i-pad,j-pad)=med;
                end
                f=0;
            else
                windowsize=windowsize+2;
                if(windowsize>smax)
                    img(i-pad,j-pad)=med;
                    f=0;
                end
            end
        end
    end
end
[m n]=size(img);
g=img(pad+1:m-pad,1+pad:n-pad);