// Function : FUN_40170808
// Address  : 0x40170808
// Size     : 88 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint * FUN_40170808(int param_1)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  uint *puVar5;
  uint *puVar6;
  undefined4 local_30 [12];
  
  local_30[0] = 0x3ffc7eac;
  FUN_40170734(0x3ffc7eac);
  uVar2 = param_1 + 0x10;
  uVar2 = (uint)(uVar2 < 8) * 8 + (uVar2 >= 8) * uVar2 + 0xf & 0xfffffff0;
  puVar4 = (uint *)&DAT_3ffc7eb0;
  puVar1 = _DAT_3ffc7eb0;
  do {
    puVar5 = (uint *)0x0;
    if (puVar1 == (uint *)0x0) {
LAB_40170850:
      FUN_40170758(local_30);
      return puVar5;
    }
    puVar5 = (uint *)puVar1[1];
    if (uVar2 <= *puVar1) {
      uVar3 = *puVar1 - uVar2;
      if (uVar3 < 8) {
        *puVar4 = (uint)puVar5;
      }
      else {
        puVar6 = (uint *)((int)puVar1 + uVar2);
        puVar6[1] = (uint)puVar5;
        puVar1 = (uint *)*puVar4;
        *puVar6 = uVar3;
        *puVar1 = uVar2;
        *puVar4 = (uint)puVar6;
      }
      puVar5 = puVar1 + 4;
      goto LAB_40170850;
    }
    puVar4 = puVar1 + 1;
    puVar1 = puVar5;
  } while( true );
}

