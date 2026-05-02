// Function : FUN_401421e8
// Address  : 0x401421e8
// Size     : 425 bytes


undefined4 FUN_401421e8(int *param_1,undefined4 param_2,byte *param_3,undefined1 *param_4)

{
  uint *puVar1;
  uint uVar2;
  uint *puVar3;
  int iVar4;
  uint local_30;
  uint uStack_2c;
  uint uStack_28;
  uint uStack_24;
  
  local_30 = ((uint)*param_3 << 0x18 | (uint)param_3[1] << 0x10 | (uint)param_3[3] |
             (uint)param_3[2] << 8) ^ param_1[1];
  uStack_2c = param_1[2] ^
              ((uint)param_3[4] << 0x18 | (uint)param_3[5] << 0x10 | (uint)param_3[7] |
              (uint)param_3[6] << 8);
  uStack_28 = param_1[3] ^
              ((uint)param_3[8] << 0x18 | (uint)param_3[9] << 0x10 | (uint)param_3[0xb] |
              (uint)param_3[10] << 8);
  puVar3 = (uint *)(param_1 + 5);
  iVar4 = *param_1;
  uStack_24 = param_1[4] ^
              ((uint)param_3[0xc] << 0x18 | (uint)param_3[0xd] << 0x10 | (uint)param_3[0xf] |
              (uint)param_3[0xe] << 8);
  do {
    if (iVar4 == 0) {
LAB_401422cf:
      uStack_28 = uStack_28 ^ *puVar3;
      uStack_24 = uStack_24 ^ puVar3[1];
      local_30 = local_30 ^ puVar3[2];
      uVar2 = puVar3[3];
      *param_4 = (char)(uStack_28 >> 0x18);
      param_4[1] = (char)(uStack_28 >> 0x10);
      param_4[2] = (char)(uStack_28 >> 8);
      param_4[4] = (char)(uStack_24 >> 0x18);
      param_4[5] = (char)(uStack_24 >> 0x10);
      memw();
      uStack_2c = uStack_2c ^ uVar2;
      param_4[6] = (char)(uStack_24 >> 8);
      param_4[8] = (char)(local_30 >> 0x18);
      param_4[9] = (char)(local_30 >> 0x10);
      param_4[10] = (char)(local_30 >> 8);
      param_4[0xc] = (char)(uStack_2c >> 0x18);
      param_4[0xd] = (char)(uStack_2c >> 0x10);
      param_4[0xf] = (char)uStack_2c;
      param_4[3] = (char)uStack_28;
      param_4[7] = (char)uStack_24;
      param_4[0xb] = (char)local_30;
      param_4[0xe] = (char)(uStack_2c >> 8);
      memw();
      memw();
      return 0;
    }
    memw();
    FUN_40141aa4(&local_30,puVar3,&uStack_28);
    FUN_40141aa4(&uStack_28,puVar3 + 2,&local_30);
    FUN_40141aa4(&local_30,puVar3 + 4,&uStack_28);
    FUN_40141aa4(&uStack_28,puVar3 + 6,&local_30);
    FUN_40141aa4(&local_30,puVar3 + 8,&uStack_28);
    iVar4 = iVar4 + -1;
    FUN_40141aa4(&uStack_28,puVar3 + 10,&local_30);
    if (iVar4 == 0) {
      puVar3 = puVar3 + 0xc;
      goto LAB_401422cf;
    }
    uStack_2c = (uint)(CONCAT44(local_30 & puVar3[0xc],local_30 & puVar3[0xc]) >> 0x1f) ^ uStack_2c;
    local_30 = (uStack_2c | puVar3[0xd]) ^ local_30;
    uStack_28 = (uStack_24 | puVar3[0xf]) ^ uStack_28;
    puVar1 = puVar3 + 0xe;
    puVar3 = puVar3 + 0x10;
    uStack_24 = (uint)(CONCAT44(uStack_28 & *puVar1,uStack_28 & *puVar1) >> 0x1f) ^ uStack_24;
    memw();
  } while( true );
}

