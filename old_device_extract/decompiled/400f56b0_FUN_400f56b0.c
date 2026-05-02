// Function : FUN_400f56b0
// Address  : 0x400f56b0
// Size     : 122 bytes


void FUN_400f56b0(uint param_1)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  
  if (0x21 < param_1) {
    (*(code *)&SUB_40094c54)("/driver/periph_ctrl.c",0x27,"_ctrl.c","nt_init");
  }
  (*(code *)&SUB_40092a70)();
  (*(code *)&SUB_40092a98)(0x3ffbdc58,0xffffffff);
  puVar1 = (uint *)FUN_400f54fc(param_1);
  uVar2 = (*(code *)&SUB_40084594)();
  uVar3 = FUN_400f53fc(param_1,0);
  memw();
  *puVar1 = uVar2 | uVar3;
  memw();
  uVar2 = (*(code *)&SUB_40084594)(puVar1);
  memw();
  *puVar1 = (uVar3 ^ 0xffffffff) & uVar2;
  memw();
  (*(code *)&SUB_40092a70)();
  (*(code *)&SUB_40092bec)(0x3ffbdc58);
  return;
}

