// Function : FUN_400f84ec
// Address  : 0x400f84ec
// Size     : 104 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_400f84ec(uint param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int aiStack_24 [9];
  
  if (_DAT_3ffc55a0 == 0) {
    iVar2 = param_1 - (param_1 & 0xffff0000);
    aiStack_24[0] = _DAT_3ffc55a0;
    memw();
    iVar3 = (*(code *)&SUB_40081e08)(param_1 & 0xffff0000,iVar2 + param_2,0,aiStack_24);
    if (iVar3 == 0) {
      return aiStack_24[0] + iVar2;
    }
    uVar1 = (*(code *)&SUB_40094b80)();
    FUN_4012113c(1,"v%d.%d\n"," twice\n",uVar1,"v%d.%d\n",iVar3);
  }
  else {
    uVar1 = (*(code *)&SUB_40094b80)();
    FUN_4012113c(1,"v%d.%d\n","er_mmap",uVar1,"v%d.%d\n");
  }
  return 0;
}

