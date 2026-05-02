// Function : FUN_400f55ec
// Address  : 0x400f55ec
// Size     : 193 bytes


void FUN_400f55ec(uint param_1)

{
  uint uVar1;
  uint uVar2;
  char cVar3;
  uint *puVar4;
  
  if (0x21 < param_1) {
    (*(code *)&SUB_40094c54)("/driver/periph_ctrl.c",0x1c,"e_reset","nt_init");
  }
  (*(code *)&SUB_40092a70)();
  (*(code *)&SUB_40092a98)(0x3ffbdc58,0xffffffff);
  cVar3 = *(char *)(param_1 + 0x3ffc5558) + -1;
  *(char *)(param_1 + 0x3ffc5558) = cVar3;
  memw();
  if (cVar3 == '\0') {
    if (param_1 < 0x1e) {
      puVar4 = (uint *)&DAT_3ff000cc;
      if ((param_1 < 0x17) && (puVar4 = (uint *)&DAT_3ff000c0, param_1 - 0x14 < 2)) {
        puVar4 = (uint *)&DAT_3ff000cc;
      }
    }
    else {
      puVar4 = (uint *)&DAT_3ff000c0;
      if (param_1 < 0x21) {
        puVar4 = (uint *)&DAT_3ff0001c;
      }
    }
    memw();
    uVar1 = (*(code *)&SUB_40084594)(puVar4);
    uVar2 = FUN_400f52e4(param_1);
    memw();
    *puVar4 = (uVar2 ^ 0xffffffff) & uVar1;
    memw();
    puVar4 = (uint *)FUN_400f54fc(param_1);
    uVar1 = (*(code *)&SUB_40084594)();
    uVar2 = FUN_400f53fc(param_1,0);
    memw();
    *puVar4 = uVar1 | uVar2;
  }
  memw();
  (*(code *)&SUB_40092a70)();
  (*(code *)&SUB_40092bec)(0x3ffbdc58);
  return;
}

