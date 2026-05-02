// Function : FUN_4013a9d8
// Address  : 0x4013a9d8
// Size     : 239 bytes


int FUN_4013a9d8(int *param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iStack_34;
  int iStack_30;
  undefined1 auStack_2c [44];
  
  iStack_30 = 0;
  memw();
  iVar1 = FUN_40141738(param_1,param_2,&iStack_34,0x30);
  if (iVar1 == 0) {
    iVar4 = *param_1 + iStack_34;
    iVar1 = FUN_4013a414(param_1,iVar4,&iStack_30,auStack_2c);
    if (iVar1 == 0) {
      iVar2 = FUN_4014195c(param_1,iVar4,&iStack_34);
      iVar1 = iVar2 + -0x3b00;
      if ((iVar2 == 0) && (iVar1 = -0x3b66, iVar4 == *param_1 + iStack_34)) {
        iVar2 = FUN_40139b60(iStack_30);
        iVar1 = -0x3c80;
        if ((iVar2 != 0) && (iVar1 = FUN_40139b8c(param_3,iVar2), iVar1 == 0)) {
          if (iStack_30 == 1) {
            uVar3 = FUN_4013a008(*param_3,param_3[1]);
            iVar1 = FUN_4013a044(param_1,iVar4,uVar3);
            if (iVar1 == 0) {
              if (*param_1 == iVar4) {
                return 0;
              }
              iVar1 = -0x3b66;
            }
          }
          else {
            iVar1 = -0x3c80;
            if (iStack_30 - 2U < 2) {
              uVar3 = FUN_4013a024(*param_3,param_3[1]);
              iVar1 = FUN_4013a108(auStack_2c,uVar3);
              if (iVar1 == 0) {
                iVar2 = FUN_4013a024(*param_3,param_3[1]);
                memw();
                iVar1 = FUN_40135f68(iVar2,iVar2 + 0x88,*param_1,iVar4 - *param_1);
                if (iVar1 == 0) {
                  iVar1 = FUN_40136114(iVar2,iVar2 + 0x88);
                }
                *param_1 = iVar4;
                if (iVar1 == 0) {
                  return 0;
                }
                memw();
              }
            }
          }
          FUN_40139b44(param_3);
        }
      }
    }
  }
  else {
    iVar1 = iVar1 + -0x3d00;
  }
  return iVar1;
}

