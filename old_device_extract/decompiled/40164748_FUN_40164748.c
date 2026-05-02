// Function : FUN_40164748
// Address  : 0x40164748
// Size     : 125 bytes


void FUN_40164748(int param_1,int param_2)

{
  undefined1 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  if (param_1 == 0) {
    memw();
    FUN_40147fe4(6,0x800,1," %s %u\n",&DAT_3f42470c,"GetRate",0x574);
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  *(undefined4 *)(param_2 + 0x1c) = *(undefined4 *)(param_1 + 0x60);
  if ((*(byte *)(param_1 + 0xb) & 4) == 0) {
    if ((*(uint *)(param_1 + 0x18) & 0x800) != 0) goto LAB_401647c3;
    iVar2 = (**(code **)(param_1 + 0x74))(*(undefined1 *)(param_1 + 0xd));
    uVar4 = iVar2 + (uint)*(byte *)(param_1 + 0xc) & 0xff;
    uVar3 = (**(code **)(param_1 + 0x74))(0x10);
    if (uVar3 < uVar4) {
      uVar4 = (**(code **)(param_1 + 0x74))(0x10);
    }
    uVar1 = *(undefined1 *)((uVar4 & 0xffff) * 0xc + *(int *)(param_1 + 0x70));
  }
  else {
    uVar1 = *(undefined1 *)(param_1 + 10);
    memw();
  }
  *(undefined1 *)(param_2 + 0xc) = uVar1;
  memw();
LAB_401647c3:
  memw();
  return;
}

