// Function : FUN_4013a044
// Address  : 0x4013a044
// Size     : 192 bytes


int FUN_4013a044(int *param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int local_24 [9];
  
  iVar1 = FUN_40141738(param_1,param_2,local_24,0x30);
  if (iVar1 == 0) {
    if (param_2 != *param_1 + local_24[0]) {
      return -0x3b66;
    }
    iVar1 = FUN_40141738(param_1,param_2,local_24,2);
    if (iVar1 == 0) {
      memw();
      iVar1 = FUN_4013b1ec(param_3,*param_1,local_24[0],0,0,0,0,0,0,0,0);
      if (iVar1 == 0) {
        *param_1 = *param_1 + local_24[0];
        memw();
        iVar1 = FUN_40141738(param_1,param_2,local_24,2);
        if (iVar1 != 0) goto LAB_4013a058;
        memw();
        iVar1 = FUN_4013b1ec(param_3,0,0,0,0,0,0,0,0,*param_1,local_24[0]);
        if (iVar1 == 0) {
          *param_1 = *param_1 + local_24[0];
          memw();
          iVar1 = FUN_4013b264(param_3);
          if ((iVar1 == 0) && (iVar1 = FUN_4013b448(param_3), iVar1 == 0)) {
            if (*param_1 != param_2) {
              return -0x3b66;
            }
            return 0;
          }
        }
      }
      return -0x3b00;
    }
  }
LAB_4013a058:
  return iVar1 + -0x3b00;
}

