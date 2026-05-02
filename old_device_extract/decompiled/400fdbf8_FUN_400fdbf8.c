// Function : FUN_400fdbf8
// Address  : 0x400fdbf8
// Size     : 116 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400fdbf8(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  char *pcVar3;
  undefined1 in_DEBUGCAUSE;
  
  uVar2 = rsr(in_DEBUGCAUSE);
  FUN_400fd498("p at 0x");
  if ((uVar2 & 1) != 0) {
    FUN_400fd498("eason: ");
  }
  if ((uVar2 & 2) != 0) {
    FUN_400fd498("leStep ");
  }
  if ((uVar2 & 4) != 0) {
    pcVar3 = "ed (";
    if ((uVar2 & 0x100) != 0) {
      (*(code *)&SUB_400916e4)(_DAT_3ffc57fc == param_1);
      uVar1 = (*(code *)&SUB_40091660)();
      FUN_400fd498("kpoint ");
      FUN_400fd498(uVar1);
      pcVar3 = "gered (";
    }
    FUN_400fd498(pcVar3);
  }
  if ((uVar2 & 8) != 0) {
    FUN_400fd498("ggered ");
  }
  if ((uVar2 & 0x10) != 0) {
    FUN_400fd498(" instr ");
  }
  if ((uVar2 & 0x20) != 0) {
    FUN_400fd498(" instr ");
  }
  return;
}

