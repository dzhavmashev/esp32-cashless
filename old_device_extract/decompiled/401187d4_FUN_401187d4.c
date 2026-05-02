// Function : FUN_401187d4
// Address  : 0x401187d4
// Size     : 212 bytes


undefined4 FUN_401187d4(int param_1,uint *param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  uint uStack_34;
  uint uStack_30;
  uint uStack_2c;
  uint uStack_28;
  char cStack_24;
  
  if ((char)param_2[4] == '\0') {
    uVar3 = *param_2;
    if (((uVar3 & 0xc0ff) == 0x80fe) || (((uVar3 & 0x8fff) - 0x1ff & 0xfffffeff) == 0)) {
      uStack_30 = param_2[1];
      uStack_2c = param_2[2];
      uStack_28 = param_2[3];
      if (((uVar3 & 0xc0ff) == 0x80fe) ||
         (cStack_24 = '\0', ((uVar3 & 0x8fff) - 0x1ff & 0xfffffeff) == 0)) {
        cStack_24 = *(char *)(param_1 + 0xee) + '\x01';
      }
      param_2 = &uStack_34;
      memw();
      uStack_34 = uVar3;
    }
  }
  memw();
  puVar2 = (undefined4 *)FUN_401854d8(param_1,param_2);
  uVar4 = 0xfa;
  if (puVar2 != (undefined4 *)0x0) {
    if (*(byte *)(puVar2 + 7) < 2) {
      puVar1 = *(undefined4 **)(param_1 + 0xd0);
      if (puVar2 == *(undefined4 **)(param_1 + 0xd0)) {
        *(undefined4 *)(param_1 + 0xd0) = *puVar2;
      }
      else {
        do {
          puVar5 = puVar1;
          if (puVar5 == (undefined4 *)0x0) goto LAB_40118855;
          puVar1 = (undefined4 *)*puVar5;
        } while (puVar2 != (undefined4 *)*puVar5);
        *puVar5 = *puVar2;
        memw();
      }
LAB_40118855:
      if (*(char *)(puVar2 + 6) != '\0') {
        memw();
        FUN_4011834c(param_1,puVar2,0x84);
      }
      if (*(code **)(param_1 + 0xf8) != (code *)0x0) {
        (**(code **)(param_1 + 0xf8))(param_1,param_2,0);
      }
      FUN_4010b078(0xf,puVar2);
    }
    else {
      *(byte *)(puVar2 + 7) = *(byte *)(puVar2 + 7) - 1;
      memw();
      memw();
    }
    uVar4 = 0;
  }
  return uVar4;
}

