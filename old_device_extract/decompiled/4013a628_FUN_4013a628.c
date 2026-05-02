// Function : FUN_4013a628
// Address  : 0x4013a628
// Size     : 442 bytes


int FUN_4013a628(int param_1,byte *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  byte *pbVar3;
  byte *pbVar4;
  int iStack_38;
  int local_34;
  byte *pbStack_30;
  uint uStack_2c;
  int iStack_28;
  byte *pbStack_24;
  
  memw();
  pbStack_30 = param_2;
  iVar1 = FUN_40141738(&pbStack_30,param_2 + param_3,&local_34,0x30);
  if (iVar1 != 0) {
LAB_4013a642:
    return iVar1 + -0x3d00;
  }
  pbVar3 = pbStack_30 + local_34;
  iVar1 = FUN_4014180c(&pbStack_30,pbVar3,&iStack_38);
  if (iVar1 != 0) goto LAB_4013a642;
  if (iStack_38 != 1) {
    return -0x3d80;
  }
  iVar1 = FUN_40141738(&pbStack_30,pbVar3,&local_34,4);
  if (iVar1 != 0) goto LAB_4013a642;
  iVar2 = param_1 + 0x7c;
  iVar1 = FUN_4013183c(iVar2,pbStack_30,local_34);
  if (iVar1 != 0) goto LAB_4013a686;
  pbStack_30 = pbStack_30 + local_34;
  if (pbStack_30 == pbVar3) {
LAB_4013a7b8:
    memw();
    iVar1 = FUN_401367a4(param_1,param_1 + 0x88,iVar2,param_1 + 0x28,0);
    if (iVar1 != 0) {
LAB_4013a686:
      FUN_40135710(param_1);
      return iVar1 + -0x3d00;
    }
  }
  else {
    memw();
    iVar1 = FUN_40141738(&pbStack_30,pbVar3,&local_34,0xa0);
    if (iVar1 == 0) {
      pbVar4 = pbStack_30 + local_34;
      if (local_34 < 1) {
        iVar1 = -0x3d60;
        goto LAB_4013a70e;
      }
      uStack_2c = (uint)*pbStack_30;
      if ((uStack_2c != 6) && (uStack_2c != 0x30)) {
        iVar1 = -0x3d62;
        goto LAB_4013a70e;
      }
      memw();
      iVar1 = FUN_40141738(&pbStack_30,pbVar4,&iStack_28);
      if (iVar1 == 0) {
        pbStack_24 = pbStack_30;
        pbStack_30 = pbStack_30 + iStack_28;
        if (pbVar4 != pbStack_30) {
          iVar1 = -0x3d66;
          memw();
          goto LAB_4013a70e;
        }
      }
      else {
        iVar1 = iVar1 + -0x3d00;
        if (iVar1 != 0) goto LAB_4013a70e;
      }
      iVar1 = FUN_4013a108(&uStack_2c,param_1);
      if (iVar1 != 0) goto LAB_4013a70e;
    }
    else if (iVar1 != -0x62) goto LAB_4013a746;
    if (pbStack_30 == pbVar3) goto LAB_4013a7b8;
    iVar1 = FUN_40141738(&pbStack_30,pbVar3,&local_34,0xa1);
    if (iVar1 != 0) {
      if (iVar1 != -0x62) {
LAB_4013a746:
        FUN_40135710(param_1);
        return iVar1 + -0x3d00;
      }
      goto LAB_4013a7b8;
    }
    pbVar3 = pbStack_30 + local_34;
    iVar1 = FUN_4014195c(&pbStack_30,pbVar3,&local_34);
    if (iVar1 != 0) goto LAB_4013a642;
    if (pbVar3 != pbStack_30 + local_34) {
      return -0x3d66;
    }
    iVar1 = FUN_40135f68(param_1,param_1 + 0x88,pbStack_30,(int)pbVar3 - (int)pbStack_30);
    if (iVar1 == 0) {
      iVar1 = FUN_40136114(param_1,param_1 + 0x88);
    }
    pbStack_30 = pbVar3;
    if (iVar1 != 0) {
      if (iVar1 != -0x4e80) {
        return -0x3d00;
      }
      goto LAB_4013a7b8;
    }
  }
  iVar1 = FUN_401362d4(param_1,iVar2);
  if (iVar1 == 0) {
    return 0;
  }
LAB_4013a70e:
  FUN_40135710(param_1);
  return iVar1;
}

