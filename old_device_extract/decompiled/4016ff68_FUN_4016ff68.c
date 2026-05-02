// Function : FUN_4016ff68
// Address  : 0x4016ff68
// Size     : 127 bytes


void FUN_4016ff68(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined1 auStack_40 [8];
  undefined4 uStack_38;
  
  FUN_40170020(param_1);
  uStack_38 = *(undefined4 *)(param_1 + -0xc);
  uVar6 = *(undefined4 *)(param_1 + -0x10);
  uVar5 = *(undefined4 *)(param_1 + -0x18);
  uVar4 = *(undefined4 *)(param_1 + -0x24);
  FUN_401701f8(*(undefined4 *)(param_1 + -0x28));
  FUN_40170020(param_1 + -0x30);
  puVar1 = (undefined4 *)FUN_40170600();
  puVar1 = (undefined4 *)*puVar1;
  puVar2 = puVar1 + 0x14;
  if ((puVar1[0xc] & 1) != 0) {
    puVar2 = (undefined4 *)*puVar1;
  }
  FUN_4016fc38(0,uVar6,auStack_40);
  iVar3 = FUN_4016fb8c(auStack_40,puVar2[-0x14],puVar2,uVar5);
  if (iVar3 != 0) {
    FUN_401702f0();
  }
  FUN_401701a8(uVar4);
  FUN_4017007c();
  FUN_4017007c();
  FUN_401710dc(puVar2);
  do {
    ill();
  } while( true );
}

