// Function : FUN_400d4b54
// Address  : 0x400d4b54
// Size     : 146 bytes


void FUN_400d4b54(uint param_1,undefined4 param_2)

{
  byte bVar1;
  byte *pbVar2;
  uint uVar3;
  uint uVar4;
  byte bStack_22;
  byte bStack_21;
  byte abStack_20 [32];
  
  if (param_1 < 0x80) {
    (*(code *)&LAB_40183b4f_1)(param_2);
  }
  else {
    if ((param_1 >> 6 & 0xffff) < 0x20) {
      pbVar2 = &bStack_22;
    }
    else {
      uVar4 = (int)(param_1 >> 6) >> 6;
      uVar3 = uVar4 & 0x3ff;
      bVar1 = (byte)uVar3;
      if ((uVar4 & 0x3f0) == 0) {
        bStack_22 = bVar1 | 0xe0;
        pbVar2 = &bStack_21;
      }
      else {
        bStack_22 = bVar1 & 0x3f | 0x80;
        bStack_21 = (byte)((int)uVar3 >> 6) | 0xf0;
        pbVar2 = abStack_20;
      }
    }
    while( true ) {
      pbVar2 = pbVar2 + -1;
      if (*pbVar2 == 0) break;
      (*(code *)&LAB_40183b4f_1)(param_2);
    }
  }
  return;
}

