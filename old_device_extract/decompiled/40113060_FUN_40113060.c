// Function : FUN_40113060
// Address  : 0x40113060
// Size     : 72 bytes


undefined1 FUN_40113060(int param_1)

{
  undefined1 uVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (param_1 == 0) {
    (*(code *)&SUB_40094c54)("lid pcb",0x824,"w_probe","lid pcb");
  }
  uVar2 = FUN_40109eec(*(int *)(param_1 + 0x7c) + -1);
  iVar3 = FUN_401102e0(param_1,0,uVar2);
  uVar1 = 0xff;
  if (iVar3 != 0) {
    FUN_40110330(iVar3);
    uVar1 = FUN_40110224(param_1,iVar3,param_1,param_1 + 0x18);
  }
  return uVar1;
}

