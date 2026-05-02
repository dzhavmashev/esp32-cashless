// Function : FUN_400f7e98
// Address  : 0x400f7e98
// Size     : 137 bytes


int FUN_400f7e98(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uStack_28;
  int aiStack_24 [9];
  
  iVar2 = FUN_400f8eb4(1,0);
  if (iVar2 == 0) {
    uVar3 = (*(code *)&SUB_40094b80)();
    FUN_4012113c(1,"_length","ota_ops",uVar3,"_length");
  }
  else {
    aiStack_24[0] = 0;
    memw();
    iVar4 = FUN_400f9060(iVar2,0,*(undefined4 *)(iVar2 + 0x10),0,aiStack_24,&uStack_28);
    iVar1 = aiStack_24[0];
    if (iVar4 == 0) {
      (*(code *)&SUB_4008b3d0)(param_1,aiStack_24[0],0x20);
      (*(code *)&SUB_4008b3d0)(param_1 + 0x20,iVar1 + 0x1000);
      (*(code *)&SUB_40081e78)(uStack_28);
    }
    else {
      uVar3 = (*(code *)&SUB_40094b80)();
      FUN_4012113c(1,"_length","tadata\n",uVar3,"_length",iVar4);
      iVar2 = 0;
    }
  }
  return iVar2;
}

