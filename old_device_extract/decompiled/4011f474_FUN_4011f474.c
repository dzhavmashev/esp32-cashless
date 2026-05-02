// Function : FUN_4011f474
// Address  : 0x4011f474
// Size     : 254 bytes


void FUN_4011f474(uint param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  undefined4 uVar5;
  char *pcVar6;
  
  if (param_2 == 0) {
    if (param_1 < 2) goto LAB_4011f4a5;
    iVar2 = (param_1 + 0x3ff62) * 0x1000;
    puVar3 = (uint *)(iVar2 + 0x1c);
    if (0x13ffc < iVar2 + 0xc010001cU) goto LAB_4011f4ad;
    uVar5 = 0x2a2;
    pcVar6 = "0x%08x\n";
LAB_4011f49c:
    do {
      (*(code *)&SUB_40094c54)("t/esp32/spiram_psram.c",uVar5,"pi_init",pcVar6);
LAB_4011f4a5:
      puVar3 = (uint *)&DAT_3ff4301c;
      if (param_1 != 0) {
        puVar3 = (uint *)&DAT_3ff4201c;
      }
LAB_4011f4ad:
      memw();
      memw();
      *puVar3 = *puVar3 | 0x30;
      if (param_1 < 2) {
        puVar3 = (uint *)&DAT_3ff43014;
        if (param_1 != 0) {
          puVar3 = (uint *)&DAT_3ff42014;
        }
      }
      else {
        iVar2 = (param_1 + 0x3ff62) * 0x1000;
        puVar3 = (uint *)(iVar2 + 0x14);
        if (iVar2 + 0xc0100014U < 0x13ffd) {
          uVar5 = 0x2a4;
          pcVar6 = "13FFC))";
          memw();
          goto LAB_4011f49c;
        }
      }
      memw();
      memw();
      *puVar3 = *puVar3 & 0xffffff0f | 0x10;
      if ((param_1 < 2) ||
         (iVar2 = param_1 + 0x3ff62, param_1 = 0x13ffc, 0x13ffc < iVar2 * 0x1000 + 0xc0100014U))
      goto LAB_4011f528;
      uVar5 = 0x2a5;
      pcVar6 = "13FFC))";
      memw();
    } while( true );
  }
  if (param_1 < 2) {
    puVar3 = (uint *)&DAT_3ff4301c;
    if (param_1 != 0) {
      puVar3 = (uint *)&DAT_3ff4201c;
    }
  }
  else {
    iVar2 = (param_1 + 0x3ff62) * 0x1000;
    param_1 = iVar2 + 0xc010001c;
    puVar3 = (uint *)(iVar2 + 0x1c);
    if (param_1 < 0x13ffd) {
      uVar5 = 0x2a7;
      pcVar6 = "13FFC))";
      goto LAB_4011f49c;
    }
  }
  uVar4 = 0xffffffcf;
  memw();
  uVar1 = *puVar3;
  goto LAB_4011f52f;
LAB_4011f528:
  memw();
  uVar1 = *puVar3;
  uVar4 = 0xfffffff0;
LAB_4011f52f:
  memw();
  *puVar3 = uVar1 & uVar4;
  memw();
  return;
}

