// Function : FUN_4011869c
// Address  : 0x4011869c
// Size     : 240 bytes


undefined4 FUN_4011869c(int param_1,uint *param_2)

{
  undefined4 *puVar1;
  uint uVar2;
  undefined4 uVar3;
  uint local_34;
  uint uStack_30;
  uint uStack_2c;
  uint uStack_28;
  char cStack_24;
  
  uVar2 = *param_2;
  uVar3 = 0xfa;
  if ((uVar2 & 0xff) == 0xff) {
    if (((char)param_2[4] == '\0') &&
       (((uVar2 & 0xc0ff) == 0x80fe || (((uVar2 & 0x8fff) - 0x1ff & 0xfffffeff) == 0)))) {
      uStack_30 = param_2[1];
      uStack_2c = param_2[2];
      uStack_28 = param_2[3];
      if (((uVar2 & 0xc0ff) == 0x80fe) ||
         (cStack_24 = '\0', ((uVar2 & 0x8fff) - 0x1ff & 0xfffffeff) == 0)) {
        cStack_24 = *(char *)(param_1 + 0xee) + '\x01';
      }
      param_2 = &local_34;
      memw();
      local_34 = uVar2;
    }
    memw();
    puVar1 = (undefined4 *)FUN_401854d8(param_1,param_2);
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)FUN_4010b058(0xf);
      uVar3 = 0xff;
      if (puVar1 == (undefined4 *)0x0) goto LAB_40118785;
      puVar1[1] = *param_2;
      puVar1[2] = param_2[1];
      puVar1[3] = param_2[2];
      puVar1[4] = param_2[3];
      *(char *)(puVar1 + 5) = (char)param_2[4];
      puVar1[6] = 0x200;
      *(undefined1 *)(puVar1 + 7) = 0;
      memw();
      *puVar1 = *(undefined4 *)(param_1 + 0xd0);
      *(undefined4 **)(param_1 + 0xd0) = puVar1;
      if (*(code **)(param_1 + 0xf8) != (code *)0x0) {
        memw();
        (**(code **)(param_1 + 0xf8))(param_1,param_2,1);
      }
      FUN_4011834c(param_1,puVar1,0x83);
      FUN_40118498(puVar1,500);
    }
    uVar3 = 0;
    *(char *)(puVar1 + 7) = *(char *)(puVar1 + 7) + '\x01';
    memw();
  }
LAB_40118785:
  memw();
  return uVar3;
}

