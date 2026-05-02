// Function : FUN_400f552c
// Address  : 0x400f552c
// Size     : 192 bytes


void FUN_400f552c(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  
  if (0x21 < param_1) {
    (*(code *)&SUB_40094c54)("/driver/periph_ctrl.c",0x11,"disable","nt_init");
  }
  (*(code *)&SUB_40092a70)();
  (*(code *)&SUB_40092a98)(0x3ffbdc58,0xffffffff);
  if (*(char *)(param_1 + 0x3ffc5558) == '\0') {
    if (param_1 < 0x1e) {
      puVar3 = (uint *)&DAT_3ff000cc;
      if ((param_1 < 0x17) && (puVar3 = (uint *)&DAT_3ff000c0, param_1 - 0x14 < 2)) {
        puVar3 = (uint *)&DAT_3ff000cc;
      }
    }
    else {
      puVar3 = (uint *)&DAT_3ff000c0;
      if (param_1 < 0x21) {
        puVar3 = (uint *)&DAT_3ff0001c;
      }
    }
    uVar1 = (*(code *)&SUB_40084594)(puVar3);
    uVar2 = FUN_400f52e4(param_1);
    memw();
    *puVar3 = uVar1 | uVar2;
    memw();
    puVar3 = (uint *)FUN_400f54fc(param_1);
    uVar1 = (*(code *)&SUB_40084594)();
    uVar2 = FUN_400f53fc(param_1,1);
    memw();
    *puVar3 = (uVar2 ^ 0xffffffff) & uVar1;
  }
  *(char *)(param_1 + 0x3ffc5558) = *(char *)(param_1 + 0x3ffc5558) + '\x01';
  memw();
  memw();
  (*(code *)&SUB_40092a70)();
  (*(code *)&SUB_40092bec)(0x3ffbdc58);
  return;
}

