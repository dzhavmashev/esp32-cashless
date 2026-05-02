// Function : FUN_4011c040
// Address  : 0x4011c040
// Size     : 119 bytes


int FUN_4011c040(undefined4 param_1,undefined1 param_2,undefined4 param_3)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  char *pcVar4;
  int aiStack_48 [2];
  undefined1 uStack_40;
  
  iVar2 = FUN_4011d10c(param_1,param_3);
  if (iVar2 != 0) {
    memw();
    memw();
    aiStack_48[0] = iVar2;
    uStack_40 = param_2;
    cVar1 = FUN_4011bff4(0x4011d01c,aiStack_48);
    if (cVar1 != '\0') {
      if (*(int *)(iVar2 + 8) == 0) goto LAB_4011c084;
      pcVar4 = "ool";
      uVar3 = 0xa8;
      while( true ) {
        while( true ) {
          (*(code *)&SUB_40094c54)("ing pcb",uVar3,"cv_data",pcVar4);
LAB_4011c084:
          if (*(int *)(iVar2 + 0x10) != 0) break;
          pcVar4 = "i_lib.c";
          uVar3 = 0xa9;
        }
        if (*(int *)(iVar2 + 0x14) == 0) break;
        pcVar4 = "ecvmbox";
        uVar3 = 0xab;
      }
      FUN_4011af6c(iVar2 + 0x10);
      FUN_4010b078(7,iVar2);
      iVar2 = 0;
    }
  }
  return iVar2;
}

