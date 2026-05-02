// Function : FUN_4018c33c
// Address  : 0x4018c33c
// Size     : 151 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4018c33c(int param_1,char param_2)

{
  code *pcVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  DAT_3ffca1e9 = 0;
  memw();
  if (DAT_3ffca1e6 == '\0') {
    pcVar1 = *(code **)(_DAT_3ffc1a34 + 0x1a0);
    memw();
  }
  else {
    if (param_2 == '\0') {
      uVar2 = 1;
      uVar3 = 0;
      if (param_1 != 0) {
        if ((_DAT_3ffca1f2 & 0x3fff) != 0) {
          uVar3 = (_DAT_3ffca1f2 & 0x3fff) >> 3;
          uVar4 = *(byte *)(param_1 + 4) & 0xfffffffe;
          uVar2 = 0;
          if ((uVar4 <= uVar3) && (uVar3 <= (uVar4 + (*(byte *)(param_1 + 1) - 4) & 0xff))) {
            uVar2 = (int)(uint)*(byte *)(param_1 + (uVar3 - uVar4) + 5) >> (_DAT_3ffca1f2 & 7) & 1;
          }
        }
        uVar3 = *(byte *)(param_1 + 4) & 1;
        if (DAT_3ffc002c != '\0') {
          uVar3 = 0;
        }
      }
    }
    else {
      FUN_4018b8d8();
      uVar2 = 0;
      uVar3 = 0;
    }
    FUN_4018c0b4(uVar2,uVar3);
    pcVar1 = *(code **)(_DAT_3ffc1a34 + 0x1a0);
  }
  (*pcVar1)(0);
  return;
}

