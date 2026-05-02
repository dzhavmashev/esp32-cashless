// Function : FUN_401378f0
// Address  : 0x401378f0
// Size     : 1032 bytes


int FUN_401378f0(uint *param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  undefined *puVar3;
  uint *puVar4;
  
  FUN_401356b4(param_1);
  FUN_40135644(param_1);
  *param_1 = param_2;
  if (param_2 == 6) {
    param_1[3] = (uint)&DAT_3f41e434;
    param_1[6] = (uint)&DAT_3f41e414;
    param_1[9] = (uint)&DAT_3f41e3f4;
    param_1[0x15] = (uint)&DAT_3f41e394;
    param_1[2] = 8;
    param_1[5] = 8;
    param_1[8] = 8;
    param_1[0x14] = 8;
    param_1[0xb] = 8;
    param_1[0xe] = 8;
    param_1[1] = 1;
    param_1[4] = 1;
    param_1[7] = 1;
    param_1[0x13] = 1;
    param_1[10] = 1;
    param_1[0xc] = (uint)&DAT_3f41e3d4;
    param_1[0xd] = 1;
    puVar3 = &DAT_3f41e3b4;
    memw();
  }
  else if (param_2 < 7) {
    if (param_2 == 3) {
      param_1[3] = (uint)&DAT_3f41e884;
      param_1[9] = (uint)&DAT_3f41e864;
      param_1[0x15] = (uint)&DAT_3f41e804;
      param_1[0x19] = (uint)&DAT_40137080;
      param_1[2] = 8;
      param_1[8] = 8;
      param_1[0x14] = 8;
      param_1[0xb] = 8;
      param_1[0xe] = 8;
      param_1[1] = 1;
      param_1[7] = 1;
      param_1[0x13] = 1;
      param_1[10] = 1;
      param_1[0xc] = (uint)&DAT_3f41e844;
      param_1[0xd] = 1;
      puVar3 = &DAT_3f41e824;
      memw();
    }
    else if (param_2 < 4) {
      if (param_2 == 1) {
        param_1[3] = (uint)&DAT_3f41e994;
        param_1[9] = (uint)&DAT_3f41e97c;
        param_1[0x19] = 0x4013780c;
        param_1[0x15] = (uint)&DAT_3f41e934;
        param_1[2] = 6;
        param_1[8] = 6;
        param_1[0x14] = 6;
        param_1[0xb] = 6;
        param_1[0xe] = 6;
        puVar3 = &DAT_3f41e94c;
        param_1[1] = 1;
        param_1[7] = 1;
        param_1[0x13] = 1;
        param_1[10] = 1;
        param_1[0xc] = (uint)&DAT_3f41e964;
        param_1[0xd] = 1;
      }
      else {
        if (param_2 != 2) {
LAB_40137920:
          *param_1 = 0;
          iVar2 = -0x4e80;
          memw();
          goto LAB_40137a86;
        }
        param_1[9] = (uint)&DAT_3f41e8f8;
        param_1[2] = 8;
        param_1[0x15] = (uint)&DAT_3f41e8a4;
        param_1[0x19] = (uint)&DAT_40137490;
        param_1[3] = (uint)&DAT_3f41e914;
        param_1[8] = 7;
        param_1[0x14] = 7;
        param_1[0xb] = 7;
        param_1[0xe] = 7;
        param_1[1] = 1;
        param_1[7] = 1;
        param_1[0x13] = 1;
        param_1[10] = 1;
        param_1[0xc] = (uint)&DAT_3f41e8dc;
        param_1[0xd] = 1;
        puVar3 = &DAT_3f41e8c0;
        memw();
      }
    }
    else if (param_2 == 4) {
      param_1[3] = (uint)&DAT_3f41e7d4;
      param_1[9] = (uint)&DAT_3f41e7a4;
      param_1[0x15] = (uint)&DAT_3f41e714;
      param_1[0x19] = (uint)&LAB_40136b00;
      param_1[2] = 0xc;
      param_1[8] = 0xc;
      param_1[0x14] = 0xc;
      param_1[0xb] = 0xc;
      param_1[0xe] = 0xc;
      param_1[1] = 1;
      param_1[7] = 1;
      param_1[0x13] = 1;
      param_1[10] = 1;
      param_1[0xc] = (uint)&DAT_3f41e774;
      param_1[0xd] = 1;
      puVar3 = &DAT_3f41e744;
      memw();
    }
    else {
      if (param_2 != 5) goto LAB_40137920;
      param_1[3] = (uint)&DAT_3f41e6d0;
      param_1[9] = (uint)&DAT_3f41e68c;
      param_1[0x15] = (uint)&DAT_3f41e5c0;
      param_1[0x19] = (uint)&DAT_40136a94;
      param_1[2] = 0x11;
      param_1[8] = 0x11;
      param_1[0x14] = 0x11;
      param_1[0xb] = 0x11;
      param_1[0xe] = 0x11;
      param_1[1] = 1;
      param_1[7] = 1;
      param_1[0x13] = 1;
      param_1[10] = 1;
      param_1[0xc] = (uint)&DAT_3f41e648;
      param_1[0xd] = 1;
      puVar3 = &DAT_3f41e604;
      memw();
    }
  }
  else {
    if (param_2 == 9) {
      param_1[0x19] = 0x40136a04;
      memw();
      iVar2 = FUN_40131700(param_1 + 4,0x1db42);
      if (iVar2 == 0) {
        puVar4 = param_1 + 1;
        iVar2 = FUN_40131700(puVar4,1);
        if (((iVar2 == 0) && (iVar2 = FUN_40131980(puVar4,0xff), iVar2 == 0)) &&
           (iVar2 = FUN_40131d74(puVar4,puVar4,0x13), iVar2 == 0)) {
          uVar1 = FUN_40131798(puVar4);
          param_1[0x16] = uVar1;
          memw();
          iVar2 = FUN_4013183c(param_1 + 0x13,&DAT_3f41e0e4,0x10);
          if (((iVar2 == 0) && (iVar2 = FUN_4013173c(param_1 + 0x13,0xfc,1), iVar2 == 0)) &&
             ((iVar2 = FUN_40131700(param_1 + 10,9), iVar2 == 0 &&
              (iVar2 = FUN_40131700(param_1 + 0x10,1), iVar2 == 0)))) {
            FUN_40131548(param_1 + 0xd);
            param_1[0x17] = 0xfe;
            memw();
            goto LAB_40137a86;
          }
        }
      }
      FUN_401356b4(param_1);
      goto LAB_40137a86;
    }
    if (param_2 < 10) {
      if (param_2 == 7) {
        param_1[3] = (uint)&DAT_3f41e364;
        param_1[6] = (uint)&DAT_3f41e334;
        param_1[9] = (uint)&DAT_3f41e304;
        param_1[0x15] = (uint)&DAT_3f41e274;
        param_1[2] = 0xc;
        param_1[5] = 0xc;
        param_1[8] = 0xc;
        param_1[0x14] = 0xc;
        param_1[0xb] = 0xc;
        param_1[0xe] = 0xc;
        param_1[1] = 1;
        param_1[4] = 1;
        param_1[7] = 1;
        param_1[0x13] = 1;
        param_1[10] = 1;
        param_1[0xc] = (uint)&DAT_3f41e2d4;
        param_1[0xd] = 1;
        puVar3 = &DAT_3f41e2a4;
        memw();
      }
      else {
        if (param_2 != 8) goto LAB_40137920;
        param_1[3] = (uint)&DAT_3f41e234;
        param_1[6] = (uint)&DAT_3f41e1f4;
        param_1[9] = (uint)&DAT_3f41e1b4;
        param_1[0x15] = (uint)&DAT_3f41e0f4;
        param_1[2] = 0x10;
        param_1[5] = 0x10;
        param_1[8] = 0x10;
        param_1[0x14] = 0x10;
        param_1[0xb] = 0x10;
        param_1[0xe] = 0x10;
        param_1[1] = 1;
        param_1[4] = 1;
        param_1[7] = 1;
        param_1[0x13] = 1;
        param_1[10] = 1;
        param_1[0xc] = (uint)&DAT_3f41e174;
        param_1[0xd] = 1;
        puVar3 = &DAT_3f41e134;
        memw();
      }
    }
    else if (param_2 == 0xb) {
      param_1[3] = (uint)&DAT_3f41e53c;
      param_1[6] = (uint)&DAT_3f41e538;
      param_1[9] = (uint)&DAT_3f41e534;
      param_1[0x14] = 8;
      param_1[0x15] = (uint)&DAT_3f41e4dc;
      param_1[0x19] = (uint)&LAB_401377e4;
      param_1[2] = 7;
      param_1[0xb] = 7;
      param_1[0xe] = 7;
      param_1[1] = 1;
      param_1[4] = 1;
      param_1[5] = 1;
      param_1[7] = 1;
      param_1[8] = 1;
      param_1[0x13] = 1;
      param_1[10] = 1;
      param_1[0xc] = (uint)&DAT_3f41e518;
      param_1[0xd] = 1;
      puVar3 = &DAT_3f41e4fc;
      memw();
    }
    else if (param_2 < 0xb) {
      param_1[3] = (uint)&DAT_3f41e5a8;
      param_1[6] = (uint)&DAT_3f41e5a4;
      param_1[9] = (uint)&DAT_3f41e5a0;
      param_1[0x15] = (uint)&DAT_3f41e558;
      param_1[0x19] = 0x401377d0;
      param_1[2] = 6;
      param_1[0x14] = 6;
      param_1[0xb] = 6;
      param_1[0xe] = 6;
      param_1[1] = 1;
      param_1[4] = 1;
      param_1[5] = 1;
      param_1[7] = 1;
      param_1[8] = 1;
      param_1[0x13] = 1;
      param_1[10] = 1;
      param_1[0xc] = (uint)&DAT_3f41e588;
      param_1[0xd] = 1;
      puVar3 = &DAT_3f41e570;
      memw();
    }
    else {
      if (param_2 != 0xc) goto LAB_40137920;
      param_1[3] = (uint)&DAT_3f41e4bc;
      param_1[6] = (uint)&DAT_3f41e4b8;
      param_1[9] = (uint)&DAT_3f41e4b4;
      param_1[0x15] = (uint)&DAT_3f41e454;
      param_1[0x19] = 0x401377f8;
      param_1[2] = 8;
      param_1[0x14] = 8;
      param_1[0xb] = 8;
      param_1[0xe] = 8;
      param_1[1] = 1;
      param_1[4] = 1;
      param_1[5] = 1;
      param_1[7] = 1;
      param_1[8] = 1;
      param_1[0x13] = 1;
      param_1[10] = 1;
      param_1[0xc] = (uint)&DAT_3f41e494;
      param_1[0xd] = 1;
      puVar3 = &DAT_3f41e474;
      memw();
    }
  }
  param_1[0xf] = (uint)puVar3;
  param_1[0x10] = 1;
  param_1[0x12] = 0x3ffbf784;
  param_1[0x11] = 1;
  memw();
  uVar1 = FUN_40131798(param_1 + 1);
  param_1[0x16] = uVar1;
  memw();
  uVar1 = FUN_40131798(param_1 + 0x13);
  iVar2 = 0;
  param_1[0x17] = uVar1;
  param_1[0x18] = 1;
LAB_40137a86:
  memw();
  return iVar2;
}

