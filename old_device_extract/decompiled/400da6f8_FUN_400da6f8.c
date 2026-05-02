// Function : FUN_400da6f8
// Address  : 0x400da6f8
// Size     : 118 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400da6f8(int param_1,char param_2)

{
  int iVar1;
  char *pcVar2;
  undefined1 auStack_34 [16];
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  FUN_400f0be8(auStack_34,&DAT_3f404943);
  FUN_400da604(param_1,2,auStack_34);
  FUN_400f0a50(auStack_34);
  *(undefined4 *)(param_1 + 0x808) = 0;
  pcVar2 = "s";
  if (param_2 == '\0') {
    pcVar2 = " %s";
  }
  FUN_400f06a4(0x3ffc5490,"cessful",pcVar2);
  iVar1 = _DAT_3ffc5708;
  memw();
  memw();
  if (iStack_24 != _DAT_3ffc5708) {
    func_0x40082ecc();
    FUN_400f0a50(auStack_34);
    thunk_FUN_401710d8(iVar1);
  }
  return;
}

