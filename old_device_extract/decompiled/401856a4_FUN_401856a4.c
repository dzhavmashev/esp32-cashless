// Function : FUN_401856a4
// Address  : 0x401856a4
// Size     : 57 bytes


undefined8 FUN_401856a4(int param_1,int param_2)

{
  param_1 = param_1 << 0x1d;
  if (param_2 == 1) {
    param_2 = 0;
  }
  else if (param_2 == 0) {
    param_2 = 0xf;
    witlb(param_1,0xf);
    isync();
  }
  else {
    if (param_2 == 2) {
      param_2 = 3;
      witlb(param_1,3);
      isync();
      goto LAB_401856b5;
    }
    if (param_2 != 3) goto LAB_401856b5;
    param_2 = 2;
  }
  wdtlb(param_1,param_2);
  dsync();
LAB_401856b5:
  return CONCAT44(param_2,param_1);
}

