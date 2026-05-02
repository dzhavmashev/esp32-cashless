// Function : FUN_4015af64
// Address  : 0x4015af64
// Size     : 158 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_4015af64(undefined4 param_1,undefined1 param_2,undefined4 param_3)

{
  int iVar1;
  undefined1 *puVar2;
  char *pcVar3;
  
  iVar1 = FUN_4014605c();
  if (iVar1 != 0) {
    FUN_40147fe4(1,0x10000,1,"type=%d",param_2);
    return iVar1;
  }
  iVar1 = FUN_40146034();
  if (iVar1 != 3) {
    FUN_401460a4();
    FUN_40147fe4(1,0x10000,1,"type=%d",param_2);
    return 0x3001;
  }
  puVar2 = (undefined1 *)(**(code **)(_DAT_3ffc1a34 + 0x16c))(8);
  if (puVar2 == (undefined1 *)0x0) {
    FUN_401460a4();
    pcVar3 = "";
  }
  else {
    *puVar2 = param_2;
    memw();
    *(undefined4 *)(puVar2 + 4) = param_3;
    memw();
    iVar1 = (*(code *)&SUB_40087bcc)(param_1,puVar2);
    if (iVar1 == 0) {
      FUN_401460a4();
      return 0;
    }
    FUN_401460a4();
    (**(code **)(_DAT_3ffc1a34 + 0xb0))(puVar2);
    pcVar3 = "type=%d";
  }
  FUN_40147fe4(6,0x10000,1,pcVar3,param_2);
  return -1;
}

