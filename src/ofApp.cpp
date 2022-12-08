#include "ofApp.h"

//--------------------------------------------------------------
// 犬を描くofDrawDog関数を定義する
void ofApp::ofDrawDog(int x, int y, int size, int r, int g, int b)
{
  ofPushMatrix();
  ofTranslate(0.5 * windowWidth, 0.5 * windowHeight);
  ofTranslate(x, y);

  // 耳
  ofSetColor(r, g, b);
  ofDrawTriangle(0.35 * size, -0.6 * size, 0.5 * size, 0, 0.25 * size, 0);
  ofDrawTriangle(-0.35 * size, -0.6 * size, -0.5 * size, 0, -0.25 * size, 0);

  // 頭
  ofDrawCircle(0, 0, 0.5 * size);

  // 鼻水 (犬が移動する際にも視覚的なアクションを起こす)
  ofSetColor(255);
  float timer = ofGetElapsedTimef(); // 経過時間を取得
  float snotLength = 0.15 * size * (sin(2.0 * timer) + 1.0);
  ofDrawEllipse(0.025 * size, 0.15 * size + 0.5 * snotLength, 0.05 * size, snotLength);

  // 鼻
  ofSetColor(0);
  ofDrawEllipse(0, 0.15 * size, 0.2 * size, 0.1 * size);

  // 目
  ofDrawCircle(-0.15 * size, 0.05 * size, 0.05 * size);
  ofDrawCircle(0.15 * size, 0.05 * size, 0.05 * size);

  ofPopMatrix();
}

//--------------------------------------------------------------
// 鼻水の色をランダムに決定
void ofApp::ofSetdogColor()
{
  dogColorR = ofRandom(50, 200);
  dogColorG = ofRandom(50, 200);
  dogColorB = ofRandom(50, 200);
}

//--------------------------------------------------------------
void ofApp::setup()
{
  // 背景は白
  ofBackground(255);
  ofSetFrameRate(60);
  ofSetCircleResolution(64);
  windowWidth = ofGetWindowWidth();
  windowHeight = ofGetWindowHeight();

  // 犬の大きさは犬全体が概ね30~50pxとなるようにランダムに決定する
  dogSize = ofRandom(30, 50);

  // 犬が最初に出現する場所は犬全体がウィンドウの内側に収まるランダムな位置とする
  dogPosX = ofRandom(-0.5 * windowWidth + 0.5 * dogSize, 0.5 * windowWidth - 0.5 * dogSize);
  dogPosY = ofRandom(-0.5 * windowHeight + 0.5 * dogSize, 0.5 * windowHeight - 0.5 * dogSize);

  // X,Y方向の移動距離が両方0の場合は再設定
  while (dogVelocityX == 0 && dogVelocityY == 0)
  {
    // X,Y方向の移動距離は-5~5pxとする
    dogVelocityX = ofRandom(-5, 5);
    dogVelocityY = ofRandom(-5, 5);
  }

  ofSetdogColor();
}

//--------------------------------------------------------------
void ofApp::update()
{
  // ウィンドウ内を犬が動き続けるようにする
  dogPosX += dogVelocityX;
  dogPosY += dogVelocityY;

  // 犬がウィンドウの端に達すると跳ね返るようにする
  if (dogPosX < -0.5 * windowWidth + 0.5 * dogSize || 0.5 * windowWidth - 0.5 * dogSize < dogPosX)
  {
    dogVelocityX *= -1;
    ofSetdogColor();
  }
  if (dogPosY < -0.5 * windowHeight + 0.5 * dogSize || 0.5 * windowHeight - 0.5 * dogSize < dogPosY)
  {
    dogVelocityY *= -1;
    ofSetdogColor();
  }
}

//--------------------------------------------------------------
void ofApp::draw()
{
  ofDrawDog(dogPosX, dogPosY, dogSize, dogColorR, dogColorG, dogColorB);
}
