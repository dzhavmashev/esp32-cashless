// Function : FUN_40186734
// Address  : 0x40186734
// Size     : 208 bytes


undefined4 FUN_40186734(int *param_1,int param_2,uint *param_3)

{
  byte *pbVar1;
  byte *pbVar2;
  byte bVar3;
  int iVar4;
  
  pbVar1 = (byte *)*param_1;
  iVar4 = param_2 - (int)pbVar1;
  if (iVar4 < 1) goto LAB_4018675d;
  if ((char)*pbVar1 < '\0') {
    bVar3 = *pbVar1 & 0x7f;
    if (bVar3 == 2) {
      if (iVar4 < 3) goto LAB_4018675d;
      pbVar2 = pbVar1 + 3;
      *param_3 = (*(ushort *)(pbVar1 + 1) & 0xff) << 8 | (uint)(*(ushort *)(pbVar1 + 1) >> 8);
      memw();
    }
    else if (bVar3 < 3) {
      if (bVar3 != 1) {
        return 0xffffff9c;
      }
      if (iVar4 == 1) goto LAB_4018675d;
      pbVar2 = pbVar1 + 2;
      *param_3 = (uint)pbVar1[1];
    }
    else if (bVar3 == 3) {
      if (iVar4 < 4) goto LAB_4018675d;
      pbVar2 = pbVar1 + 4;
      *param_3 = (uint)pbVar1[1] << 0x10 | (uint)pbVar1[2] << 8 | (uint)pbVar1[3];
      memw();
    }
    else {
      if (bVar3 != 4) {
        return 0xffffff9c;
      }
      if (iVar4 < 5) goto LAB_4018675d;
      pbVar2 = pbVar1 + 5;
      *param_3 = (uint)pbVar1[1] << 0x18 | (uint)pbVar1[2] << 0x10 | (uint)pbVar1[4] |
                 (uint)pbVar1[3] << 8;
      memw();
    }
    *param_1 = (int)pbVar2;
    memw();
  }
  else {
    *param_1 = (int)(pbVar1 + 1);
    *param_3 = (uint)*pbVar1;
  }
  if (*param_3 <= (uint)(param_2 - *param_1)) {
    return 0;
  }
LAB_4018675d:
  memw();
  return 0xffffffa0;
}

