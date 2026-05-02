// Function : FUN_4016fa60
// Address  : 0x4016fa60
// Size     : 129 bytes


/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x4016fa8a) overlaps instruction at (ram,0x4016fa89)
    */
/* WARNING: Type propagation algorithm not settling */

byte * FUN_4016fa60(uint param_1,byte *param_2,byte *param_3,undefined4 *param_4)

{
  uint uVar1;
  undefined *puVar2;
  undefined **ppuVar3;
  byte *unaff_a10;
  byte *in_t0;
  uint local_30;
  uint uStack_2c;
  
  if (param_1 == 0x50) {
    in_t0 = *(byte **)((uint)(param_3 + 3) & 0xfffffffc);
    unaff_a10 = (byte *)((undefined4 *)((uint)(param_3 + 3) & 0xfffffffc) + 1);
    goto LAB_4016fb35;
  }
  uVar1 = param_1 & 0xf;
  if (0xc < uVar1) {
    unaff_a10 = (byte *)(*(code *)&SUB_40094bc8)();
    goto LAB_4016fb1d;
  }
  ppuVar3 = &switchD_4016fa8d::switchdataD_3f424b54;
  puVar2 = (&switchD_4016fa8d::switchdataD_3f424b54)[uVar1];
  switch(uVar1) {
  case 0:
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case 1:
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case 2:
  case 5:
    in_t0 = (byte *)(int)(short)puVar2;
    goto LAB_4016facc;
  case 3:
    *(undefined **)(puVar2 + 0x20) = puVar2;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case 4:
    flix();
    param_1 = 0xd8104ad;
    ppuVar3 = (undefined **)(uint)*param_3;
    uStack_2c = (uint)param_3[1] << 8;
    goto code_r0x4016fab7;
  case 6:
    in_t0 = (byte *)(local_30 | (uint)&switchD_4016fa8d::switchdataD_3f424b54);
    break;
  default:
    in_t0 = (byte *)(local_30 | (uint)&switchD_4016fa8d::switchdataD_3f424b54);
    break;
  case 0xb:
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case 0xc:
code_r0x4016fab7:
    in_t0 = (byte *)(uStack_2c | (uint)ppuVar3);
LAB_4016facc:
    unaff_a10 = param_3 + 2;
  }
LAB_4016fb1d:
  if (in_t0 != (byte *)0x0) {
    if ((param_1 & 0x70) == 0x10) {
      param_2 = param_3;
    }
    in_t0 = in_t0 + (int)param_2;
    if ((char)param_1 < '\0') {
      in_t0 = *(byte **)in_t0;
    }
  }
LAB_4016fb35:
  *param_4 = in_t0;
  return unaff_a10;
}

