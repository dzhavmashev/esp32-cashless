// Function : FUN_4010323c
// Address  : 0x4010323c
// Size     : 327 bytes


void FUN_4010323c(int param_1,int param_2,int param_3)

{
  undefined1 *puVar1;
  int iVar2;
  int iVar3;
  undefined1 *puVar4;
  uint uVar5;
  undefined4 uVar6;
  uint uVar7;
  undefined1 uVar8;
  undefined4 uStack_30;
  undefined1 *puStack_2c;
  undefined1 auStack_26 [38];
  
  uVar7 = 0;
  uVar5 = *(uint *)(param_1 + 0x1f0);
  if ((((uVar5 != 0x8000) && ((uVar5 & 0x30000) == 0)) && (uVar7 = 3, (uVar5 & 0x18de0) == 0)) &&
     ((uVar7 = 2, *(int *)(param_1 + 0x1e8) == 2 && (uVar7 = 1, uVar5 == 0x400)))) {
    uVar7 = 0;
  }
  memw();
  (*(code *)&SUB_4008b3d0)(auStack_26,param_1 + 0x23a,6);
  iVar2 = FUN_40105c8c(uVar5);
  uVar6 = 0x5f;
  if (iVar2 == 0x18) {
    uVar6 = 0x67;
  }
  memw();
  iVar3 = FUN_4010544c(param_1,3,0,uVar6,&uStack_30,&puStack_2c);
  puVar1 = puStack_2c;
  if (iVar3 != 0) {
    uVar8 = 0xfe;
    if (*(int *)(param_1 + 0x240) == 2) {
      uVar8 = 2;
    }
    *puStack_2c = uVar8;
    memw();
    if (*(int *)(param_1 + 0x114) == 0) {
      uVar5 = 0x800;
    }
    else {
      uVar5 = 0xb00;
      if (iVar2 == 0) {
        uVar5 = 0xa00;
      }
    }
    uVar5 = uVar7 | uVar5;
    if (param_2 != 0) {
      uVar5 = uVar5 | 0x400;
    }
    if (param_3 != 0) {
      uVar5 = uVar5 | 8;
    }
    puStack_2c[1] = (char)(uVar5 >> 8);
    puStack_2c[2] = (char)uVar5;
    memw();
    puStack_2c[3] = 0;
    puStack_2c[4] = 0;
    memw();
    memw();
    (*(code *)&SUB_4008b3d0)(puStack_2c + 5,param_1 + 0x16c,8);
    (*(code *)&LAB_4018503f_1)(param_1 + 0x16c,8);
    if (iVar2 == 0x18) {
      puVar1[0x65] = 0;
      puVar1[0x66] = 0;
      memw();
    }
    else {
      puStack_2c[0x5d] = 0;
      puStack_2c[0x5e] = 0;
      memw();
      memw();
    }
    puVar4 = (undefined1 *)0x0;
    if ((uVar5 & 0x100) != 0) {
      puVar4 = puVar1 + 0x4d;
    }
    memw();
    FUN_401031a8(param_1,param_1 + 0x44,*(undefined4 *)(param_1 + 0x9c),uVar7,auStack_26,0x888e,
                 iVar3,uStack_30,puVar4);
    FUN_401054b4(iVar3);
  }
  return;
}

