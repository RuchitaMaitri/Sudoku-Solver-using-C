# -*- coding: utf-8 -*-
import cv2
import numpy as np
#read image
img=cv2.imread('Capture.jpg',0)
img_org=cv2.imread('Capture.jpg')
print(img)
cv2.imshow('image',img)
cv2.waitKey(0)
cv2.destroyAllWindows()
#write image
cv2.imwrite('Capture_copy.jpg',img)

#blurr image- avg method
avg_blurr_img=cv2.blur(img,(10,10))
cv2.imshow('avg_blurr_img',avg_blurr_img)
cv2.waitKey(0)
cv2.destroyAllWindows()

#blurr image- median method
median_blurr_img=cv2.blur(img,(10,10))
cv2.imshow('median_blurr_img',median_blurr_img)
cv2.waitKey(0)
cv2.destroyAllWindows()

#blurr image- guassian method
guassian_blurr_img=cv2.blur(img,(5,5),0)
cv2.imshow('guassian_blurr_img',guassian_blurr_img)
cv2.waitKey(0)
cv2.destroyAllWindows()
#this is final

#blurr image- bilateral filter method
bilateral_blurr_img=cv2.blur(img,(10,10),0)
cv2.imshow('bilateral_blurr_img',bilateral_blurr_img)
cv2.waitKey(0)
cv2.destroyAllWindows()

cv2.imshow('avg_blurr_img',avg_blurr_img)
cv2.imshow('median_blurr_img',median_blurr_img)
cv2.imshow('guassian_blurr_img',guassian_blurr_img)
cv2.imshow('bilateral_blurr_img',bilateral_blurr_img)
cv2.waitKey(0)
cv2.destroyAllWindows()

#Thresholding- simple
ret , th = cv2.threshold(np.uint8(guassian_blurr_img),200,255,cv2.THRESH_BINARY)
cv2.imshow('th',th)
cv2.waitKey(0)
cv2.destroyAllWindows()

#Thresholding- adaptive-MEAN
th1 = cv2.adaptiveThreshold(img,255,cv2.ADAPTIVE_THRESH_MEAN_C,cv2.THRESH_BINARY,5,2)
cv2.imshow('th1',th1)
cv2.waitKey(0)
cv2.destroyAllWindows()

#Thresholding- adaptive-GUASSIAN
th1 = cv2.adaptiveThreshold(guassian_blurr_img,255,cv2.ADAPTIVE_THRESH_GAUSSIAN_C,cv2.THRESH_BINARY,5,2)
cv2.imshow('th1',th1)
cv2.waitKey(0)
cv2.destroyAllWindows() 
#this is final

#HoughlineP Transform
edges=cv2.Canny(th1,50,150,apertureSize =3)
cv2.imshow('edges',edges)
cv2.waitKey(0)
cv2.destroyAllWindows() 
img_copy = img_org
lines=cv2.HoughLinesP(edges,1,np.pi/180,100,minLineLength=50,maxLineGap=20)
for line in lines:
    x1,y1,x2,y2 = line[0]
    cv2.line(img_copy,(x1,y1),(x2,y2),(0,255,0),2)

cv2.imshow('img_copy',img_copy)
cv2.waitKey(0)
cv2.destroyAllWindows() 

#Find the contours
contours, hierarchy = cv2.findContours(th1,cv2.RETR_TREE,cv2.CHAIN_APPROX_NONE)
cv2.drawContours(img,contours,-1,(0,255,0),3)
cv2.imshow('img',img)
cv2.waitKey(0)
cv2.destroyAllWindows() 

#pick up the contour with highest area
def find_contour_areas(contours):
    areas = []
    for cnt in contours: 
        cont_area = cv2.contourArea(cnt)
        areas.append(cont_area)
    return areas 
##print contour areas before sorting
print("contour areas before sorting",  find_contour_areas(contours))
#sorting contours from larger area to smaller area
sorted_contours_by_area = sorted(contours,key=cv2.contourArea, reverse=True)
print("contour areas before sorting",  find_contour_areas(sorted_contours_by_area))
    

cv2.drawContours(img,sorted_contours_by_area,8,(0,255,0),3)
cv2.imshow('img',img)
cv2.waitKey(0)
cv2.destroyAllWindows() 







