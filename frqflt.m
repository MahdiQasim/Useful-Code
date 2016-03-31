% Basic image filters in frequency domain.

function [g,h]=frqflt(img,varargin)
error(nargchk(2,5,nargin))
[m n]=size(img);
method=varargin{1};

if strcmp(method,'NOTCH')
    img=fft2(img);
else
    img=fftsh(img);
    img=fft2(img);
end

switch method
    
% Ideal low pass filter
case 'ILPF'
   
    Do=varargin{2};
    for u=1:m
        for v=1:n
            D(u,v)=((u-(m/2))^2+(v-(n/2))^2)^0.5;
            if D(u,v)<=Do
               h(u,v)=1;
            else
               h(u,v)=0;
            end
        end
    end
    mesh(h);
    g=h.*img;
    g=ifft2(g);
    g=real(g);
    g=fftsh(g);
           
    
% Ideal high pass filter    
case 'IHPF'
    Do=varargin{2};
    for u=1:m
        for v=1:n
            D(u,v)=((u-(m/2))^2+(v-(n/2))^2)^0.5;
            if D(u,v)>Do
               h(u,v)=1;
            else
               h(u,v)=0;
            end
        end
    end
    mesh(h);
    g=h.*img;
    g=ifft2(g);
    g=real(g);
    g=fftsh(g);
     
case 'BLPF'

    if length(varargin)<3
        error('Not enough inputs for this option.')
    else
        Do=varargin{2};
        ord=varargin{3};
        for u=1:m
            for v=1:n
                D(u,v)=((u-(m/2))^2+(v-(n/2))^2)^0.5;
                h(u,v)=1/(1+((D(u,v)/Do)^(2*ord)));
            end
        end
        mesh(h);
        g=h.*img;
        g=ifft2(g);
        g=real(g);
        g=fftsh(g);
    end

case 'BHPF'

    if length(varargin)<3
        error('Not enough inputs for this option.')
    else
        Do=varargin{2};
        ord=varargin{3};
        for u=1:m
            for v=1:n
                D(u,v)=((u-(m/2))^2+(v-(n/2))^2)^0.5;
                h(u,v)=1/(1+((Do/D(u,v))^(2*ord)));
            end
        end
        mesh(h);
        g=h.*img;
        g=ifft2(g);
        g=real(g);
        g=fftsh(g);
    end

% Gaussian low pass filter
case 'GLPF'
   
        Do=varargin{2};
        for u=1:m
            for v=1:n
                D(u,v)=((u-(m/2))^2+(v-(n/2))^2)^0.5;
                h(u,v)=exp(-1*((D(u,v)^2)/(2*Do*Do)));
            end
        end
        mesh(h);
        g=h.*img;
        g=ifft2(g);
        g=real(g);
        g=fftsh(g);

        
% Gaussian High pass filter
case 'GHPF'

        Do=varargin{2};
        for u=1:m
            for v=1:n
                D(u,v)=((u-(m/2))^2+(v-(n/2))^2)^0.5;
                h(u,v)=1-(exp(-1*((D(u,v)^2)/(2*Do*Do))));
            end
        end
        mesh(h);
        g=h.*img;
        g=ifft2(g);
        g=real(g);
        g=fftsh(g);

% Nocth filter
case 'NOTCH'
      
       if length(varargin)<3
        error('Not enough inputs for this option.')
       else
        h=ones(m,n);
        x=varargin{2};
        y=varargin{3};
        h(x,y)=0;
        mesh(h);
        img=h.*img;
        g=ifft2(img);
        g=real(g);
       end
 
% Homomorphic filter
case 'HOMO'
        
       if length(varargin)<3
        error('Not enough inputs for this option.')
       else
        Do=varargin{2};
        c=varargin{3};
        vec=varargin{4};
        YL=vec(1);
        YH=vec(2);
        for u=1:m
            for v=1:n
                D(u,v)=((u-(m/2))^2+(v-(n/2))^2)^0.5;
                x1=(D(u,v)*D(u,v))/(Do*Do);
                x2=exp(-c*x1);
                h(u,v)=(YH-YL)*(1-x2)+Yl;
            end
        end
        mesh(h);
        g=h.*img;
        g=ifft2(g);
        g=real(g);
        g=fftsh(g);
       end
otherwise 
error('Unknown filtering method.')
end
g=uint8(g);                            