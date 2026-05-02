// Function : FUN_400f65f0
// Address  : 0x400f65f0
// Size     : 122 bytes


undefined4 FUN_400f65f0(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  if (param_1 < 3) {
    iVar3 = param_1 * 0x10 + 0x3ffbdc7c;
    (*(code *)&SUB_40092a98)(iVar3,0xffffffff);
    uVar4 = *(uint *)(*(int *)(param_1 * 4 + 0x3ffc5588) + 0xa0) & 0x101;
    iVar2 = *(int *)(param_1 * 0x10 + 0x3ffbdc78);
    memw();
    *(uint *)(iVar2 + 0x10) = uVar4;
    memw();
    memw();
    *(uint *)(iVar2 + 0xc) = uVar4 | *(uint *)(iVar2 + 0xc);
    memw();
    (*(code *)&SUB_40092bec)(iVar3);
    uVar1 = 0;
  }
  else {
    uVar1 = (*(code *)&SUB_40094b80)();
    memw();
    FUN_4012113c(1,"th","_select",uVar1,"th","ata_len",0x18a);
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

