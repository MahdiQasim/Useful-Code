% Spatial domain image's filters.

function fimg=spflt(img,type,d1,d2,q)
img=double(img);
r=floor(d1/2);
c=floor(d2/2);
img=padarray(img,[r c],'replicate');
[m n]=size(img);
switch lower(type);
    
    % Arithmetic mean filter
    case 'amean'
    
    for i=1+r:m-r
        for j=1+c:n-c
            fimg(i-r,j-c)=sum(sum(img(i-r:i+r,j-c:j+c)/(d1*d2)));
        end
    end
    
    % Geometric mean filter
    case 'gmean'
        
     for i=1+r:m-r
        for j=1+c:n-c
          fimg(i-r,j-c)=prod(prod(img(i-r:i+r,j-c:j+c)))^(1/(d1*d2));
        end
     end
     
     
    % Harmonic mean filter 
    case 'hmean'
        
    for i=1+r:m-r
        for j=1+c:n-c
        x=d1*d2;
        y=img(i-r:i+r,j-c:j+c);
        y=1./y;
        y=sum(sum(y));
        fimg(i-r,j-c)=x/y;
        end
    end
    
    % Contraharmonic mean filter
    case 'chmean'
        
    for i=1+r:m-r
        for j=1+c:n-c
        x=sum(sum(img(i-r:i+r,j-c:j+c)))^(q+1);
        y=sum(sum(img(i-r:i+r,j-c:j+c)))^(q);
        fimg(i-r,j-c)=x/y;
        end
    end
    
    % Median mean filter
    case 'median'
            
    for i=1+r:m-r
        for j=1+c:n-c
        x= img(i-r:i+r,j-c:j+c);
        x=reshape(x,1,d1*d2);
        x=sort(x);
        fimg(i-r,j-c)=x(ceil((d1*d2)/2));
        end
    end
    
    % Max mean filter
    case 'max'
        
       for i=1+r:m-r
          for j=1+c:n-c
        x= img(i-r:i+r,j-c:j+c);
        fimg(i-r,j-c)=max(max(x));
          end
       end
       
    % Min mean filter   
    case 'min'
       for i=1+r:m-r
          for j=1+c:n-c
        x= img(i-r:i+r,j-c:j+c);
        fimg(i-r,j-c)=min(min(x));
          end
       end
       
    % Midpoint mean filter
    case 'midpoint'
        
       for i=1+r:m-r
          for j=1+c:n-c  
        x=img(i-r:i+r,j-c:j+c);
        x=reshape(x,1,d1*d2);
        x=sort(x);
        fimg(i-r,j-c)=0.5*(x(1)+x(d1*d2));
          end
       end
       
    % Alpha-Trimmed mean filter
    case 'atmean'
        
       for i=1+r:m-r
          for j=1+c:n-c
              mask=img(i-r:i+r,j-r:j+r);
              [x y]=size(mask);
              mask=reshape(mask,1,x*y);
              mask=sort(mask);
              t=floor(q/2);
              fimg(i-r,j-c)=(sum(mask(1+t:length(mask)-t)))/((x*y)-2*t);
          end
       end
       
 
    otherwise
        error('Unknown filter type.')
end
fimg=uint8(fimg);


end