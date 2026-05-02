// Function : FUN_400e09a4
// Address  : 0x400e09a4
// Size     : 113 bytes


float FUN_400e09a4(byte *param_1)

{
  byte bVar1;
  float fVar2;
  undefined1 auStack_30 [8];
  undefined1 uStack_28;
  
  fVar2 = 0.0;
  if (param_1 != (byte *)0x0) {
    bVar1 = param_1[8] & 0x7f;
    if (bVar1 == 6) {
      fVar2 = (float)*param_1 / 1.0;
    }
    else if (bVar1 < 7) {
      if (3 < bVar1) {
        uStack_28 = 0;
        FUN_400d3f78(*(undefined4 *)param_1,auStack_30);
        fVar2 = (float)FUN_400e09a4(auStack_30);
      }
    }
    else if (bVar1 == 10) {
      fVar2 = (float)(*(code *)&SUB_4000c8c0)(*(undefined4 *)param_1,*(undefined4 *)(param_1 + 4));
    }
    else if (bVar1 == 0xc) {
      fVar2 = (float)(*(code *)&SUB_40002b90)(*(undefined4 *)param_1,*(undefined4 *)(param_1 + 4));
    }
    else if (bVar1 == 8) {
      fVar2 = (float)(*(code *)&SUB_4000c8b0)(*(undefined4 *)param_1,*(undefined4 *)(param_1 + 4));
    }
  }
  return fVar2;
}

