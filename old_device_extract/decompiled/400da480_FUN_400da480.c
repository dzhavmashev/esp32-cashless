// Function : FUN_400da480
// Address  : 0x400da480
// Size     : 112 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_400da480(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  undefined1 *puVar4;
  
  FUN_400f0780(0x3ffc5490,"connect");
  iVar1 = FUN_400e6a84(0x3ffc4d78);
  pcVar3 = "nection";
  if (iVar1 != 0) {
    iVar2 = FUN_400e6ab4(0x3ffc4d78,"nection");
    if (iVar2 != 0) {
      FUN_400f06a4(0x3ffc5490,"or mTLS",iVar2);
      return 0;
    }
    puVar4 = &DAT_3ffc4da0;
    if ((DAT_3ffc4daf & 0x80) == 0) {
      puVar4 = _DAT_3ffc4da0;
    }
    FUN_400ec768(param_1,puVar4);
    puVar4 = &DAT_3ffc4d80;
    if ((DAT_3ffc4d8f & 0x80) == 0) {
      puVar4 = _DAT_3ffc4d80;
    }
    FUN_400ec77c(param_1,puVar4);
    puVar4 = &DAT_3ffc4d90;
    if ((DAT_3ffc4d9f & 0x80) == 0) {
      puVar4 = _DAT_3ffc4d90;
    }
    FUN_400ec790(param_1,puVar4);
    pcVar3 = "ed: %d\n";
  }
  FUN_400f0780(0x3ffc5490,pcVar3);
  return iVar1;
}

