// Function : FUN_40164174
// Address  : 0x40164174
// Size     : 55 bytes


undefined4 FUN_40164174(int param_1,undefined1 param_2,char param_3)

{
  byte bVar1;
  undefined4 uVar2;
  
  if (param_3 != '\0') {
    bVar1 = *(byte *)(param_1 + 0x82);
    if (bVar1 == 1) {
      uVar2 = FUN_401640dc(param_2);
      return uVar2;
    }
    if (bVar1 == 0) {
      uVar2 = FUN_4016413c();
      return uVar2;
    }
    if (bVar1 < 6) {
      uVar2 = FUN_40164070();
      return uVar2;
    }
  }
  uVar2 = FUN_40186ca8(param_1);
  return uVar2;
}

