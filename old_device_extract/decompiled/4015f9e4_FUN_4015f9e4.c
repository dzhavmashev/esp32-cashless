// Function : FUN_4015f9e4
// Address  : 0x4015f9e4
// Size     : 40 bytes


void FUN_4015f9e4(uint param_1,char param_2)

{
  int iVar1;
  
  if (param_2 == '\0') {
    iVar1 = (param_1 & 0xff) * 10;
    *(undefined1 *)(iVar1 + 0x3ffca1b4) = 0;
    *(undefined1 *)(iVar1 + 0x3ffca1b5) = 0;
    memw();
    memw();
    FUN_40165e1c();
  }
  return;
}

