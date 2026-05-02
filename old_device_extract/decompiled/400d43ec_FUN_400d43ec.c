// Function : FUN_400d43ec
// Address  : 0x400d43ec
// Size     : 323 bytes


uint FUN_400d43ec(int *param_1,int *param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  byte bVar4;
  int iVar5;
  int iVar6;
  int in_a12;
  undefined8 uStack_2c;
  uint uStack_24;
  
  bVar4 = *(byte *)(param_2 + 2) & 0x7f;
  if (bVar4 == 5) {
    uStack_2c = (*(code *)&LAB_40183af3_1)(param_2);
    iVar5 = (int)((ulonglong)uStack_2c >> 0x20);
    if ((int)uStack_2c == 0) {
      *(byte *)(param_1 + 2) = *(byte *)(param_1 + 2) & 0x80;
      return 1;
    }
    if (in_a12 == 1) {
      *(byte *)(param_1 + 2) = *(byte *)(param_1 + 2) & 0x80 | 4;
      *(undefined8 *)param_1 = uStack_2c;
      return 1;
    }
    uStack_24 = uStack_24 & 0xffffff00;
    iVar6 = FUN_40183bf4(param_3,(int)uStack_2c,iVar5,uStack_24);
    if (iVar6 == 0) {
      *(byte *)(param_1 + 2) = *(byte *)(param_1 + 2) & 0x80;
    }
    else {
      *param_1 = iVar6;
      *(byte *)(param_1 + 2) = *(byte *)(param_1 + 2) & 0x80 | 5;
      param_1[1] = iVar5;
    }
    return (uint)(iVar6 != 0);
  }
  if (bVar4 < 6) {
    if (bVar4 == 3) {
      iVar6 = *param_2;
      iVar5 = param_2[1];
      if (iVar6 == 0) goto LAB_400d44d0;
      uStack_2c._0_4_ = iVar6;
      uStack_2c._4_4_ = iVar5;
      iVar1 = FUN_40183b74(param_3,&uStack_2c);
      if (iVar1 == 0) {
        iVar1 = *(int *)(param_3 + 4);
        uVar2 = iVar1 + iVar5 + 1;
        if (*(uint *)(param_3 + 8) < uVar2) {
          *(undefined1 *)(param_3 + 0x10) = 1;
LAB_400d44d0:
          *(byte *)(param_1 + 2) = *(byte *)(param_1 + 2) & 0x80;
          return 0;
        }
        *(uint *)(param_3 + 4) = uVar2;
        if (iVar1 == 0) goto LAB_400d44d0;
        for (iVar3 = 0; iVar5 != iVar3; iVar3 = iVar3 + 1) {
          *(undefined1 *)(iVar1 + iVar3) = *(undefined1 *)(iVar6 + iVar3);
        }
        *(undefined1 *)(iVar1 + iVar5) = 0;
      }
      *(byte *)(param_1 + 2) = *(byte *)(param_1 + 2) & 0x80 | 3;
      *param_1 = iVar1;
      goto LAB_400d4419;
    }
  }
  else if ((bVar4 == 0x20) || (bVar4 == 0x40)) {
    *(byte *)(param_1 + 2) = bVar4 | *(byte *)(param_1 + 2) & 0x80;
    *param_1 = 0;
    param_1[1] = 0;
    uVar2 = FUN_400d4538(param_1,param_2,param_3);
    return uVar2;
  }
  *(byte *)(param_1 + 2) = bVar4 | *(byte *)(param_1 + 2) & 0x80;
  iVar5 = param_2[1];
  *param_1 = *param_2;
LAB_400d4419:
  param_1[1] = iVar5;
  return 1;
}

