﻿// --------------------------------------------------------------------------------------------------------------------
// <copyright file="OpCodeBlock.cs" company="">
//   
// </copyright>
// <summary>
//   
// </summary>
// --------------------------------------------------------------------------------------------------------------------

namespace Il2Native.Logic
{
    using System.Collections.Generic;
    using System.Linq;

    using Il2Native.Logic.CodeParts;

    using OpCodesEmit = System.Reflection.Emit.OpCodes;

    /// <summary>
    /// </summary>
    public class OpCodeBlock : OpCodePart
    {
        /// <summary>
        /// </summary>
        /// <param name="opCodes">
        /// </param>
        /// <param name="runDetect">
        /// </param>
        /// <param name="detectOnly">
        /// </param>
        public OpCodeBlock(OpCodePart[] opCodes)
            : base(OpCodesEmit.Nop, 0, 0)
        {
            this.OpCodes = opCodes;
        }

        /// <summary>
        /// </summary>
        public OpCodePart[] OpCodes { get; private set; }

        /// <summary>
        /// </summary>
        public override int GroupAddressStart
        {
            get
            {
                return this.OpCodes[0].GroupAddressStart;
            }
        }

        /// <summary>
        /// </summary>
        public override int GroupAddressEnd
        {
            get
            {
                return this.OpCodes[this.OpCodes.Length - 1].GroupAddressEnd;
            }
        }
    }
}